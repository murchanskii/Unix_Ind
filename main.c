#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "my_commands/my_functions.h"

// DONE
// ls
// cd
// rm
// rmdir
// mkdir
// tail
// free

// NOT DONE
// ps


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

// главная функция, цикл ввода строк (разбивка конвейера, запуск команды)
int main()
{
    char cmdline[1024];
    char *p, *cmds[256], *token;
    int cmd_cnt;

    shell_active = 1;

    while( shell_active )
    {
        printf("[%s]# ", getenv("PWD"));
        fflush(stdout);

        fgets(cmdline,1024,stdin);
        if( (p = strstr(cmdline,"\n")) != NULL ) p[0] = 0;

        replace_env_var(cmdline);

        token = strtok(cmdline, "|");
        for(cmd_cnt = 0; token && cmd_cnt < 256; cmd_cnt++ )
        {
            cmds[cmd_cnt] = strdup(token);
            token = strtok(NULL, "|");
        }
        cmds[cmd_cnt] = NULL;

        if( cmd_cnt > 0 )
        {
            exec_conv(cmds,cmd_cnt,0);
        }
    }

    return 0;
}