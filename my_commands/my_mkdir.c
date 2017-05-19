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

    if (!access(new_dir, F_OK)) {
        printf("my_mkdir: cannot create \'%s\': File exists\n", pch + 1);
        free(new_dir);
        return;
    }

    if (mkdir(new_dir, 0777)) {
        printf("my_mkdir: cannot create '%s': No such file or directory\n", path);
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

        /*int count = 0;
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
        free(temp_path);*/

        char *path = malloc(strlen(full_path) - strlen(getenv("PWD")) + 1);
        strcpy(path, full_path + strlen(getenv("PWD")) + 1);

        strcpy(full_path, getenv("PWD"));
        create_dirs(full_path, path, flag_p, flag_v);
        free(full_path);
    }
    return 0;
}