//
// Created by murchanskii on 17.05.17.
//

// done: -p -v

#include "my_functions.h"
#include <stdio.h>
#include <sys/stat.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>

void create_dirs(char *full_path, char *path, int flag_p, int flag_v)
{

    char *new_dir = malloc(strlen(full_path) * sizeof(char));
    strcat(full_path, "/");
    strcat(full_path, path);
    strcpy(new_dir, full_path);
    char *pch = strchr(path, '/');

    int situation = 0;

    if (flag_p && pch != NULL) {
        situation = 1;
        strcpy(path, pch + 1);
        new_dir[strlen(new_dir) - strlen(path) - 1] = 0;
    }

    pch = strrchr(new_dir, '/');
    char error_msg[256];

    if (mkdir(new_dir, 0777)) {
        strcpy(error_msg, "my_mkdir: cannot create \'");
        strcat(error_msg, pch + 1);
        strcat(error_msg, "\'");
        perror(error_msg);
        free(new_dir);
        return;
    }

    if (flag_v)
        printf("my_mkdir: created directory '%s'\n", new_dir + strlen(getenv("PWD")) + 1);

    if (situation)
        create_dirs(new_dir, path, flag_p, flag_v);
    else {
        free(new_dir);
        return;
    }
    free(new_dir);
}

SHCMD(mkdir)
{
    int n_start = calc_n_start();

    if (np == n_start) {
        printf("my_mkdir: missing operand\n");
        return 0;
    }

    int flag_p = 0, flag_v = 0;
    getopt_for_dirs(&flag_p, &flag_v);

    for (int i = n_start; i < np; i++) {
        char cur_param[1000];
        char *full_path = malloc(strlen(getenv("PWD")) + strlen(cur_param) + 2);

        initialisation(full_path, cur_param, &i);

        char *path = malloc(strlen(full_path) - strlen(getenv("PWD")) + 1);
        strcpy(path, full_path + strlen(getenv("PWD")) + 1);

        strcpy(full_path, getenv("PWD"));
        create_dirs(full_path, path, flag_p, flag_v);
        free(full_path);
    }
    return 0;
}