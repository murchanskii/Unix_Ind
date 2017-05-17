//
// Created by murchanskii on 17.05.17.
//

// done: -p -v (almost, "not existing dir", ect)

#include "my_functions.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <getopt.h>

void remove_parents(char *full_path, int n, int flag_v)
{
    char *cur_path = full_path;
    char *pch = strrchr(cur_path, '/');
    char filename[1000];
    strcpy(filename, cur_path + strlen(getenv("PWD")) + 1);
    // add more errors
    if (remove(cur_path))
        printf("my_rmdir: cannot remove \'%s\': No such file or directory\n", filename);
    else if (flag_v)
        printf("my_rmdir: removing directory, \'%s\'\n", filename);
    if (n > 0)
    {
        cur_path[pch - cur_path] = 0;
        remove_parents(cur_path, n - 1, flag_v);
    }
    else
        return;
}

SHCMD(rmdir)
{
    if (np < 2)
    {
        printf("my_rmdir: missing operand\n");
        return 0;
    }
    int n_start = 1;
    for (int i = 1; i < np; i++)
        if (params[i][0] == '-')
            n_start++;

    int opt = getopt(np, params, "pv");
    int flag_p = 0, flag_v = 0;
    while( opt != -1 ) {
        switch (opt) {
            case 'p':
                flag_p = 1;
                break;
            case 'v':
                flag_v = 1;
                break;
            default:
                /* You won't actually get here. */
                break;
        }
        opt = getopt(np, params, "pv");
    }
    optind = 1;

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

        if (!file_exists(filename, path))
        {
            printf("my_rmdir: cannot remove \'%s\': No such file or directory\n", filename);
            free(full_path);
            free(path);
            return 0;
        }
        if (is_regular_file(full_path)) {
            printf("my_rmdir: cannot remove '%s': Not a directory\n", filename);
            free(path);
            return 0;
        }

        int count = 0;
        for (int j = 0; j < strlen(cur_param); j++)
            if (cur_param[j] == '/')
                count++;

        if (flag_p)
            remove_parents(full_path, count, flag_v);
        else
            if (remove(full_path))
                printf("my_rmdir: failed to remove \'%s\': Directory not empty\n", filename);
        free(full_path);
        free(path);
    }

    return 0;
}