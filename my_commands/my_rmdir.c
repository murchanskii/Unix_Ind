//
// Created by murchanskii on 17.05.17.
//

// done: -p -v

#include "my_functions.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void remove_dirs(char *full_path, int n, int flag_v)
{
    char error_msg[256];
    char *cur_path = full_path;
    char filename[1000];
    strcpy(filename, cur_path + strlen(getenv("PWD")) + 1);

    char *pch = strrchr(cur_path, '/');

    if (flag_v)
        printf("my_rmdir: removing directory, \'%s\'\n", filename);

    if (is_regular_file(cur_path)) {
        errno = ENOTDIR;
        strcpy(error_msg, "my_rmdir: cannot remove '");
        strcat(error_msg, filename);
        strcat(error_msg, "'");
        perror(error_msg);
        return;
    }

    if (remove(cur_path)) {
        strcpy(error_msg, "my_rmdir: cannot remove '");
        strcat(error_msg, filename);
        strcat(error_msg, "'");
        perror(error_msg);
        return;
    }

    if (n > 0) {
        cur_path[pch - cur_path] = 0;
        remove_dirs(cur_path, n - 1, flag_v);
    }
    else
        return;
}

SHCMD(rmdir)
{
    int n_start = calc_n_start();

    if (np == n_start) {
        printf("my_rmdir: missing operand\n");
        return 0;
    }

    int flag_p = 0, flag_v = 0;
    getopt_for_dirs(&flag_p, &flag_v);

    for (int i = n_start; i < np; i++) {
        char cur_param[1000];
        char *full_path = malloc(strlen(getenv("PWD")) + strlen(cur_param) + 2);

        initialisation(full_path, cur_param, &i);

        int count = 0;
        char *temp_path = malloc(strlen(full_path) - strlen(getenv("PWD")) + 1);
        if (cur_param[0] == '/')
            strcpy(temp_path, full_path + strlen(getenv("PWD")) + 1);
        else
            strcpy(temp_path, cur_param);

        if (flag_p) {
            for (int j = 0; j < strlen(temp_path); j++)
                if (temp_path[j] == '/')
                    count++;
        }
        free(temp_path);
        remove_dirs(full_path, count, flag_v);
        free(full_path);
    }
    return 0;
}