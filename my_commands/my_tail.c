//
// Created by murchanskii on 20.05.17.
//

// done: -n

#include "my_functions.h"
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

SHCMD(tail)
{
    int n_start = calc_n_start();

    if (np == n_start) {
        printf("my_tail: missing operand\n");
        return 0;
    }

    int opt = getopt(np, params, "n:");
    int flag_n = 0, num_lines = 10;
    while( opt != -1 ) {
        switch (opt) {
            case 'n':
                flag_n = 1;
                num_lines = atoi(optarg);
                n_start++;
                break;
            default:
                /* You won't actually get here. */
                break;
        }
        opt = getopt(np, params, "n");
    }
    optind = 1;

    for (int i = n_start; i < np; i++) {
        char cur_param[1000];
        char *full_path = malloc(strlen(getenv("PWD")) + strlen(cur_param) + 2);

        initialisation(full_path, cur_param, &i);

        if (access(full_path, F_OK))
            printf("my_tail: cannot read '%s': No such file or directory\n", cur_param);


        if (!is_regular_file(full_path))
            printf("my_tail: cannot read '%s': Is a directory\n", cur_param);

        int ch = 0, all_lines = 0;
        FILE *file = fopen(full_path, "r");

        while(!feof(file)) {
            ch = fgetc(file);
            if(ch == '\n')
                all_lines++;
        }

        fseek(file, 0, SEEK_SET);

        const int length = 256;
        char line[length];
        char *c = 0;
        long line_count = 0;

        if(num_lines > all_lines)
            num_lines = all_lines;

        do {
            c = fgets(line, length, file);
            if (c != NULL && (line_count > all_lines - num_lines))
                printf("%s", line);
            line_count++;
        } while (c != NULL);

        free(full_path);
    }

    return 0;
}