//
// Created by murchanskii on 27.05.17.
//

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_functions.h"

char *get_env_name(char *env_name)
{
    char var[strlen(env_name)];

    int i = 0;
    while (env_name[i]) {
        var[i] = (char) toupper(env_name[i]);
        i++;
    }
    var[i] = 0;

    return getenv(var);
}

void replace_env_var(char *cmdline)
{
    char *start_pch = strchr(cmdline, '$');
    while (start_pch != NULL)
    {
        char env_name[128];
        char new_cmdline[256];
        char strtok_temp[256];
        strcpy(strtok_temp, start_pch);
        strcpy(env_name, strtok(strtok_temp, " \\?%|\"<>.,*/:;"));

        char *env_desc = get_env_name(env_name + 1);

        if (env_desc != NULL) {
            strncpy(new_cmdline, cmdline, start_pch - cmdline);
            new_cmdline[start_pch - cmdline] = 0;

            strcat(new_cmdline, env_desc);
            strcat(new_cmdline, start_pch + strlen(strtok_temp));

            strcpy(cmdline, new_cmdline);
        }
        start_pch = strchr(start_pch + 1, '$');
    }
}