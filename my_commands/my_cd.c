//
// Created by murchanskii on 09.05.17.
//

// вроде сделан :т

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>
#include "my_functions.h"

int check_for_existing(char *path)
{
    if (chdir(path)) {
        errno = ENOENT;
        perror("my_cd");
        return 0;
    }
    else
        return 1;
}

SHCMD(cd)
{
    if (np == 1 || strcmp(params[1], "~") == 0) {
        setenv("PWD", getenv("HOME"), 1);
        return 0;
    }
    if (starts_with(params[1], "/")) {
        if (check_for_existing(params[1]))
            setenv("PWD", params[1], 1);
        else {
            errno = ENOENT;
            perror("unixInd: cd");
            return 0;
        }
    }
    else
    {
        char new_dir[255];
        strcpy(new_dir, getenv("PWD"));
        if (starts_with(params[1],"..")) {
            char p[255];
            strcpy(p, params[1]);
            while (starts_with(p, ".."))
            {
                char *pch = strrchr(new_dir, '/');
                new_dir[pch - new_dir] = 0;
                strcpy(p, p + 3);
            }
            if (check_for_existing(new_dir))
                setenv("PWD", new_dir, 1);
            else {
                errno = ENOENT;
                perror("unixInd: cd");
                return 0;
            }
        }
        else {
            strcat(new_dir, "/");
            strcat(new_dir, params[1]);
            if (check_for_existing(new_dir))
                setenv("PWD", new_dir, 1);
            else {
                errno = ENOENT;
                perror("unixInd: cd");
                return 0;
            }
        }
    }
    return 0;
}