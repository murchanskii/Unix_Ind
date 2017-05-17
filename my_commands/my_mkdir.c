//
// Created by murchanskii on 17.05.17.
//

#include "my_functions.h"
#include <stdio.h>
#include <sys/stat.h>
#include <memory.h>
#include <stdlib.h>

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

SHCMD(mkdir)
{
    if (np < 2)
    {
        printf("my_mkdir: missing operand\n");
        return 0;
    }
    int n_start = 1;
    for (int i = 1; i < np; i++)
        if (params[i][0] == '-')
            n_start++;
    for (int i = n_start; i < np; i++)
    {
        char cur_param[1000];
        strcpy(cur_param, params[i]);

        if (strstr(cur_param, "\""))
            do {
                i++;
                strcat(cur_param, " ");
                strcat(cur_param, params[i]);
            } while(!strstr(params[i], "\""));

        int situation = 0; // 1 - absolute path; 2 - relative path; 3 - filename
        if (strstr(cur_param, "/")) {
            if (cur_param[0] == '/')
                situation = 1;
            else
                situation = 2;
        }
        else
            situation = 3;

        char *path;
        char *full_path;

        remove_certain_chars(cur_param, '\"');

        switch(situation)
        {
            case 1: // absolute path
                full_path = malloc(strlen(cur_param) + 1);
                strcpy(full_path, cur_param);
                break;
            default: // case 2, 3
                full_path = malloc(strlen(getenv("PWD")) + strlen(cur_param) + 2);
                strcpy(full_path, getenv("PWD"));
                strcat(full_path, "/");
                strcat(full_path, cur_param);
                break;
        }
        char *pch = strrchr(full_path, '/');
        char *filename = malloc(strlen(pch));
        strcpy(filename, pch + 1);
        path = malloc(strlen(full_path) + 1);
        strcpy(path, full_path);
        path[pch - full_path] = 0;

        if (file_exists(filename, path))
        {
            printf("my_mkdir: cannot create directory '%s': File exists\n", filename);
            free(full_path);
            free(path);
            return 0;
        }
        int ret = mkdir(full_path, 0700);
        if (ret) {
            printf("my_mkdir: cannot create directory '%s': No such file or directory\n", path);
        }
        free(full_path);
        free(path);
    }

    return 0;
}