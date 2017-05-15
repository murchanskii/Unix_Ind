//
// Created by murchanskii on 11.05.17.
//

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "my_functions.h"

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
        printf("rmdir: missing operand\n");
        return 0;
    }
    if (np > n_start)
        to_one_string(n_start, filename, params);
    strcpy(filename, filename + 1);
    // end initializing FILENAME

    char pth[255];
    if (strstr(filename, "/")) {
        strcpy(pth, filename);
        strcpy(filename, strrchr(filename, '/') + 1);
    }

    // start file check for existence
    char *path;

    if (pth[1] == NULL) {
        path = malloc(strlen(getenv("PWD")) * sizeof(char));
        strcpy(path, getenv("PWD"));
    }
    else {
        char *pch = strrchr(pth, '/');
        pth[pch - pth] = 0;
        path = malloc(strlen(pth) * sizeof(char));
        strcpy(path, pth);
    }

    if (!file_exists(filename, path)) {
        printf("rm: cannot remove \'%s\': No such file or directory\n", filename);
        return 0;
    }
    // end file check for existence

    // start check if file is a DIRECTORY
    strcat(path, "/");
    strcat(path, filename);
    if (is_regular_file(path)) {
        printf("rmdir: failed to remove '%s': Not a directory\n", filename);
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

    ret = remove(path);
    if (ret)
        printf("rm: failed to remove \'%s\': Directory not empty\n", filename);
    free(path);
    return 0;
}