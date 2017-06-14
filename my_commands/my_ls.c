//
// Created by murchanskii on 09.05.17.
//

// в принципе сделан, но без total в -l (не знаю, что именно там показано)

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <dirent.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include "my_functions.h"

//для scandir в ls
int filter (const struct dirent *d)
{
    if (d->d_name[0] == '.')    // all is ok
        return 0;
    return 1;
}

SHCMD(ls)
{
    int opt = getopt(np, params, "lai");

    struct dirent **entry;
    opendir((const char *) getenv("PWD"));
    int n = 0;
    n = scandir(getenv("PWD"), &entry, filter, alphasort);
    int flag_i = 0, flag_l = 0;

    while( opt != -1 ) {
        switch (opt) {
            case 'a':
                n = scandir(getenv("PWD"), &entry,  NULL, alphasort);
                break;
            case 'l':
                flag_l = 1;
                break;
            case 'i':
                flag_i = 1;
                break;
            default:
                /* You won't actually get here. */
                break;
        }
        opt = getopt(np, params, "lai");
    }
    optind = 1;

    struct stat st;

    for (int i = 0; i < n; i++) {

        lstat(entry[i]->d_name, &st);
        if (flag_i)
            printf("%zu ", st.st_ino);
        if (flag_l)
        {
            int mode = st.st_mode;
            static char *rights = "rwxrwxrwx";
            if (S_ISDIR(mode))
                printf("d");
            else
                printf("-");

            int j;
            for(j = 0; j<9; j++)
            {
                printf(mode&256 ? "%c" : "-", rights[j]);
                mode <<= 1;
            }
            printf(" %zu ", st.st_nlink); // кол-во жёстких ссылок
            printf("%-7s ", getpwuid(st.st_uid)->pw_name); // имя владельца
            printf("%-7s ", getgrgid(st.st_gid)->gr_name); // имя группы
            printf("%5zu", st.st_size);// размер в байтах
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%B %e %H:%M", localtime((const time_t *) &st.st_mtim));
            printf(" %s ", buffer); // дата модификации
            printf("%s\n", entry[i]->d_name);
        }
        else
            printf("%s\t", entry[i]->d_name);
    }
    for (int  i = 0; i < n; i++)
        free(entry[i]);
    free(entry);

    printf ("\n");
    return 0;
}