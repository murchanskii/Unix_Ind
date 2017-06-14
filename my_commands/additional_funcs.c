//
// Created by murchanskii on 19.05.17.
//

#include "my_functions.h"
#include <memory.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void initialisation(char *full_path, char *cur_param, int *i)
{
    strcpy(cur_param, params[*i]);

    if (strstr(cur_param, "\""))
        do {
            *i += 1;
            strcat(cur_param, " ");
            strcat(cur_param, params[*i]);
        } while(!strstr(params[*i], "\""));

    int situation = 0; // 1 - absolute path; 2 - relative path; 3 - filename
    if (strstr(cur_param, "/")) {
        if (cur_param[0] == '/')
            situation = 1;
        else
            situation = 2;
    }
    else
        situation = 3;

    remove_certain_chars(cur_param, '\"');

    switch(situation)
    {
        case 1: // absolute path
            strcpy(full_path, cur_param);
            break;
        default: // case 2, 3
            strcpy(full_path, getenv("PWD"));
            strcat(full_path, "/");
            strcat(full_path, cur_param);
            break;
    }
}

void remove_certain_chars(char *str, char c)
{
    char *pr = str, *pw = str;
    while(*pr)
    {
        *pw = *pr++;
        pw += (*pw != c);
    }
    *pw = 0;
}

int my_atoi(char *str)
{
    char *temp_str = malloc(strlen(str) + 1);
    for (int i = 0, j = 0 ; i < strlen(str); i++)
        if (str[i] <= '9' && str[i] >= '0')
            temp_str[j++] = str[i];
    int k = atoi(temp_str);
    free(temp_str);
    return k;
}

void getopt_for_dirs(int *flag_p, int *flag_v)
{
    int opt = getopt(np, params, "pv");
    while( opt != -1 ) {
        switch (opt) {
            case 'p':
                *flag_p = 1;
                break;
            case 'v':
                *flag_v = 1;
                break;
            default:
                /* You won't actually get here. */
                break;
        }
        opt = getopt(np, params, "pv");
    }
}

int calc_n_start()
{
    int n_start = 1;
    for (int i = 1; i < np; i++)
        if (params[i][0] == '-')
            n_start++;
    return n_start;
}

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int starts_with (char *str, char *start)
{
    int i = 0;
    char *temp = malloc(strlen(str) * sizeof(char));
    while (str[i] == ' ')
        i++;
    strcpy(temp, str + i);
    char *result = strstr(temp, start);
    return ( result - temp == 0) ? 1 : 0;
}

// выполнение команды с параметрами
void my_exec(char *cmd)
{
    char *token;

    token = strtok(cmd, " ");
    np = 0;
    while( token && np < 255 )
    {
        params[np++] = token;
        token = strtok(NULL, " ");
    }
    params[np] = NULL;

    // выполнение встроенных команд
    if( IS_CMD(pwd) )
        SHCMD_EXEC(pwd);
    else
    if( IS_CMD(exit) )
        SHCMD_EXEC(exit);
    else
    if ( IS_CMD(ls) )
        SHCMD_EXEC(ls);
    else
    if ( IS_CMD(cd) )
        SHCMD_EXEC(cd);
    else
    if ( IS_CMD(ps) )
        SHCMD_EXEC(ps);
    else
    if ( IS_CMD(rm) )
        SHCMD_EXEC(rm);
    else
    if ( IS_CMD(rmdir) )
        SHCMD_EXEC(rmdir);
    else
    if ( IS_CMD(mkdir) )
        SHCMD_EXEC(mkdir);
    else
    if ( IS_CMD(tail) )
        SHCMD_EXEC(tail);
    else
    if ( IS_CMD(free) )
        SHCMD_EXEC(free);
    else
    { // иначе вызов внешней команды
        execvp(params[0], params);
        perror("exec"); // если возникла ошибка при запуске
    }
}

// рекурсивная функция обработки конвейера
// параметры: строка команды, количество команд в конвейере, текущая (начинается с 0 )
int exec_conv(char *cmds[], int n, int curr)
{
    int fd[2],i;
    if( pipe(fd) < 0 )
    {
        printf("Cannot create pipe\n");
        return 1;
    }

    if( n > 1 && curr < n - 2 )
    { // first n-2 cmds
        if( fork() == 0 )
        {
            dup2(fd[1], 1);
            close(fd[0]);
            close(fd[1]);
            my_exec(cmds[curr]);
            exit(0);
        }
        if( fork() == 0 )
        {
            dup2(fd[0], 0);
            close(fd[0]);
            close(fd[1]);
            exec_conv(cmds,n,++curr);
            exit(0);
        }
    }
    else
    { // 2 last cmds or if only 1 cmd
        if( n == 1 && (strcmp(cmds[0],"exit") == 0 ||  starts_with(cmds[0], "cd") == 1) )
        { // для случая команды exit обходимся без fork, иначе не сможем завершиться
            close(fd[0]);
            close(fd[1]);
            my_exec(cmds[curr]);
            return 0;
        }
        if( fork() == 0 )
        {
            if( n > 1 ) // if more then 1 cmd
                dup2(fd[1], 1);
            close(fd[0]);
            close(fd[1]);
            my_exec(cmds[curr]);
            exit(0);
        }
        if( n > 1 && fork()==0 )
        {
            dup2(fd[0], 0);
            close(fd[0]);
            close(fd[1]);
            my_exec(cmds[curr+1]);
            exit(0);
        }
    }
    close(fd[0]);
    close(fd[1]);

    for( i = 0 ; i < n ; i ++ ) // ожидание завершения всех дочерних процессов
        wait(0);

    return 0;
}