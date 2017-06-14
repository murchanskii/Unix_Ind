//
// Created by murchanskii on 31.05.17.
//

#include "my_functions.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void statement_cut(char *str, char *word_to_cut)
{
    int i = 0;
    while (str[i] == ' ') {
        i++;
    }
    strcpy(str, str + i);
    str = strstr(str, word_to_cut);
    strcpy(str, str + strlen(word_to_cut));
    i = 0;
    while (str[i] == ' ') {
        i++;
    }
    strcpy(str, str + i);
    i = 0;
    while (str[strlen(str) - i] == ' ')
        i++;
    str[strlen(str) - i] = 0;
}

void condition_handler(char *cmd)
{
    char *cmds[256];
    cmds[0] = strdup(cmd);
    cmds[1] = NULL;
    exec_conv(cmds, 1, 0);
}

int cond(char *cmd)
{
    statement_cut(cmd, "[");
    char *pch = strstr(cmd, "]");
    cmd[pch - cmd] = 0;
    int i = 0;
    while(cmd[strlen(cmd) - i] == ' ')
        i++;
    cmd[strlen(cmd) - i] = 0;

    char temp[5 + strlen(cmd)];
    strcpy(temp, "test ");
    strcat(temp, cmd);
    strcpy(cmd, temp);

    char *token;

    token = strtok(cmd, " ");
    np = 0;
    while( token && np < 255 )
    {
        params[np++] = token;
        token = strtok(NULL, " ");
    }
    params[np] = NULL;

    int result;

    if( fork() == 0 )
    {
        execvp(params[0], params);
        exit(-1);
    }
    wait(&result);
    return result;
}

void if_expression(char *cmdline)
{
    char temp[strlen(cmdline)];
    strcpy(temp, cmdline);
    char *pcond = strtok(temp, ";");
    char *pthen = strtok(NULL, ";");
    char *pelse_or_fi = strtok(NULL, ";");
    char *pfi = strtok(NULL, ";");

    // initialisation of condition strings

    if (pcond && pelse_or_fi && pthen) {
        if (!starts_with(pthen, "then")) {
            printf("\x1b[31m" "unixInd: syntax error near unexpected token ';'\n" "\x1b[0m");
            return;
        }

        statement_cut(pcond, "if");
        statement_cut(pthen, "then");

        if (pfi)
        {
            if (!starts_with(pelse_or_fi, "else")) {
                printf("\x1b[31m" "unixInd: syntax error near unexpected token ';'\n" "\x1b[0m");
                return;
            }
            statement_cut(pelse_or_fi, "else");
        }
        else {
            if (!starts_with(pelse_or_fi, "fi")) {
                printf("\x1b[31m" "unixInd: syntax error near unexpected token ';'\n" "\x1b[0m");
                return;
            }
        }
    }
    else {
        printf("\x1b[31m" "unixInd: syntax error near unexpected token ';'\n" "\x1b[0m");
        return;
    }

    // check if condition
    if (!cond(pcond))
        condition_handler(pthen);
    else
        if (pfi)
            condition_handler(pelse_or_fi);
}