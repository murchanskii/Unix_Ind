//
// Created by murchanskii on 19.05.17.
//

#include "my_functions.h"
#include <memory.h>
#include <stdlib.h>
#include <getopt.h>

void initialisation(char *full_path, char *cur_param, int *i)
{
    strcpy(cur_param, params[*i]);

    if (strstr(cur_param, "\""))
        do {
            *i += 1;
            strcat(cur_param, " ");
            strcat(cur_param, params[*i]);
        } while(!strstr(params[*i], "\""));

    int situation = 0; // 1 - absolute path; 2 - relative path; 3 - filename
    if (strstr(cur_param, "/")) {
        if (cur_param[0] == '/')
            situation = 1;
        else
            situation = 2;
    }
    else
        situation = 3;

    remove_certain_chars(cur_param, '\"');

    switch(situation)
    {
        case 1: // absolute path
            strcpy(full_path, cur_param);
            break;
        default: // case 2, 3
            strcpy(full_path, getenv("PWD"));
            strcat(full_path, "/");
            strcat(full_path, cur_param);
            break;
    }
}

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

void getopt_for_dirs(int *flag_p, int *flag_v)
{
    int opt = getopt(np, params, "pv");
    while( opt != -1 ) {
        switch (opt) {
            case 'p':
                *flag_p = 1;
                break;
            case 'v':
                *flag_v = 1;
                break;
            default:
                /* You won't actually get here. */
                break;
        }
        opt = getopt(np, params, "pv");
    }
}

int calc_n_start()
{
    int n_start = 1;
    for (int i = 1; i < np; i++)
        if (params[i][0] == '-')
            n_start++;
    return n_start;
}