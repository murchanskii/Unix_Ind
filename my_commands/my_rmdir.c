//
// Created by murchanskii on 11.05.17.
//

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "my_functions.h"

// done: -p -v

SHCMD(rmdir)
{
    // start initializing FILENAME
    char filename[255];
    int ret;
    int n_start = 1;
    strcpy(filename, "");
    for (int i = 1; i < np; i++)
        if (params[i][0] == '-')
            n_start++;
    if (np < n_start)
    {
        printf("my_rmdir: missing operand\n");
        return 0;
    }
    if (np > n_start)
        to_one_string(n_start, filename, params);
    strcpy(filename, filename + 1);

    char pth[255];
    if (strstr(filename, "/")) {
        strcpy(pth, filename);
        strcpy(filename, strrchr(filename, '/') + 1);
    }
    // end initializing FILENAME

    // start forming PATH to file
    char *path;

    if (pth[1] == NULL) {
        path = malloc(strlen(getenv("PWD")) * sizeof(char) + strlen(filename) * sizeof(char) + 2);
        strcpy(path, getenv("PWD"));
    }
    else {
        char *pch = strrchr(pth, '/');
        pth[pch - pth] = 0;
        if (pth[0] != '/') {
            path = malloc(strlen(getenv("PWD")) * sizeof(char) + strlen(pth) * sizeof(char) +
                          strlen(filename) * sizeof(char) + 3);
            strcpy(path, getenv("PWD"));
            strcat(path, "/");
            strcat(path, pth);
        }
        else {
            path = malloc(strlen(pth) * sizeof(char) + strlen(filename) * sizeof(char) + 2);
            strcpy(path, pth);
        }

    }
    // end forming PATH to file

    // start file check for existence
    if (!file_exists(filename, path)) {
        printf("my_rmdir: cannot remove \'%s\': No such file or directory\n", filename);
        free(path);
        return 0;
    }
    // end file check for existence

    // start check if file is a DIRECTORY
    strcat(path, "/");
    strcat(path, filename);
    if (is_regular_file(path)) {
        printf("my_rmdir: cannot remove '%s': Not a directory\n", filename);
        free(path);
        return 0;
    }
    // end check if file is a DIRECTORY

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

    if (flag_p)
    {
        char *dirs_to_delete = params[n_start];
        while(dirs_to_delete[1] != NULL)
        {
            char *pch = strrchr(dirs_to_delete, '/');
            strcpy(filename, pch + 1);
            if (flag_v)
                printf("my_rmdir: removing directory, \'%s\'\n", dirs_to_delete);
            if (remove(path)) {
                printf("my_rmdir: failed to remove \'%s\': Directory not empty\n", filename);
                free(path);
                return 0;
            }
            dirs_to_delete[pch - dirs_to_delete] = 0;
            pch = strrchr(path, '/');
            path[pch - path] = 0;
        }
        strcpy(filename, params[n_start]);
    }
    if(flag_v)
        printf("my_rmdir: removing directory, \'%s\'\n", filename);
    ret = remove(path);
    if (ret)
        printf("my_rmdir: failed to remove \'%s\': Directory not empty\n", filename);
    free(path);
    return 0;
}