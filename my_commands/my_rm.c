//
// Created by murchanskii on 11.05.17.
//

// CAN'T HANDLE FILENAMES WITH SPACES

// done: -i -d

#include <stdio.h>
#include <memory.h>
#include <getopt.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my_functions.h"

void to_one_string(int n_start, char *filename, char **params)
{
    for (int i = n_start; i < np; i++) {
        strcat(filename, " ");
        strcat(filename, params[i]);
    }
}

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int file_exists(char *filename, char *path)
{
    int file_exists = 0;
    struct dirent **entry;
    opendir(path);
    int n = scandir(path, &entry, NULL, alphasort);
    for (int i = 0; i < n; i++)
        if (!strcmp(filename, entry[i]->d_name)) {
            file_exists = 1;
            break;
        }
    for (int  i = 0; i < n; i++)
        free(entry[i]);
    free(entry);
    if (file_exists)
        return 1;
    else
        return 0;
}

SHCMD(rm)
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
        printf("my_rm: missing operand\n");
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

    int opt = getopt(np, params, "di");
    int flag_d = 0, flag_i = 0;
    while( opt != -1 ) {
        switch (opt) {
            case 'd':
                flag_d = 1;
                break;
            case 'i':
                flag_i = 1;
                break;
            default:
                /* You won't actually get here. */
                break;
        }
        opt = getopt(np, params, "di");
    }
    optind = 1;

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

    // start file check for existence
    if (!file_exists(filename, path)) {
        printf("my_rm: cannot remove \'%s\': No such file or directory\n", filename);
        free(path);
        return 0;
    }
    // end file check for existence

    // start check if file is a DIRECTORY
    strcat(path, "/");
    strcat(path, filename);
    if (!flag_d && !is_regular_file(path)) {
        printf("my_rm: cannot remove '%s': Is a directory\n", filename);
        free(path);
        return 0;
    }
    // end check if file is a DIRECTORY

    int is_doc = 0;
    if (is_regular_file(path))
        is_doc = 1;

    if (flag_i)
    {
        if (is_doc) {
            FILE *fd = fopen(filename, "r");
            fseek(fd, 0, SEEK_END);
            long size = ftell(fd);
            fclose(fd);
            if (size == 0)
                printf("my_rm: remove regular empty file \'%s\'? ", filename);
            else
                printf("my_rm: remove regular file \'%s\'? ", filename);
        }
        else
            printf("my_rm: remove directory '%s'? ", filename);
        char answer[50];
        scanf("%49s", answer);
        answer[strlen(answer)] = 0;
        if (strcmp(answer, "y") || strcmp(answer, "Y")) {
            free(path);
            return 0;
        }
    }

    ret = remove(path);
    if (ret)
        printf("my_rm: cannot remove \'%s\': Directory not empty\n", filename);
    free(path);
    return 0;
}