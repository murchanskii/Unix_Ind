//
// Created by murchanskii on 11.05.17.
//

// done: -i -d -f

#include <stdio.h>
#include <memory.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "my_functions.h"

SHCMD(rm)
{
    int n_start = calc_n_start();

    if (np == n_start) {
        printf("my_rm: missing operand\n");
        return 0;
    }

    int opt = getopt(np, params, "dif");
    int flag_d = 0, flag_i = 0, flag_f = 0;
    while( opt != -1 ) {
        switch (opt) {
            case 'd':
                flag_d = 1;
                break;
            case 'i':
                flag_i = 1;
                break;
            case 'f':
                flag_f = 1;
            default:
                /* You won't actually get here. */
                break;
        }
        opt = getopt(np, params, "dif");
    }
    optind = 1;

    for (int i = n_start; i < np; i++) {
        int next_move = 0;

        char cur_param[1000];
        char *full_path = malloc(strlen(getenv("PWD")) + strlen(cur_param) + 2);

        initialisation(full_path, cur_param, &i);
        char error_msg[256];

        if (access(full_path, F_OK)) {
            free(full_path);
            if (!flag_f) {
                errno = ENOENT;
                strcpy(error_msg, "my_rm: cannot remove \'");
                strcat(error_msg, cur_param);
                strcat(error_msg, "\'");
                perror(error_msg);
            }
            next_move = 1;
        }

        if (!next_move) {

            int is_doc = 0;

            if (is_regular_file(full_path))
                is_doc = 1;
            else if (!flag_d) {
                free(full_path);
                if (!flag_f)
                {
                    errno = EISDIR;
                    strcpy(error_msg, "my_rm: cannot remove \'");
                    strcat(error_msg, cur_param);
                    strcat(error_msg, "\'");
                    perror(error_msg);
                }
                next_move = 1;
            }

            if (!next_move) {
                if (flag_i && !flag_f) {
                    if (is_doc) {
                        FILE *fd = fopen(full_path, "r");
                        fseek(fd, 0, SEEK_END);
                        long size = ftell(fd);
                        fclose(fd);
                        if (size == 0)
                            printf("my_rm: remove regular empty file \'%s\'? ", cur_param);
                        else
                            printf("my_rm: remove regular file \'%s\'? ", cur_param);
                    } else
                        printf("my_rm: remove directory '%s'? ", cur_param);
                    char answer[50];
                    scanf("%49s", answer);
                    answer[strlen(answer)] = 0;
                    if (strcmp(answer, "y") && strcmp(answer, "Y")) {
                        free(full_path);
                        next_move = 1;
                    }
                }

                if (!next_move) {
                    if (remove(full_path))
                        if (!flag_f) {
                            strcpy(error_msg, "my_rm: cannot remove \'");
                            strcat(error_msg, cur_param);
                            strcat(error_msg, "\'");
                            perror(error_msg);
                        }
                    free(full_path);
                }
            }
        }
    }
    return 0;
}