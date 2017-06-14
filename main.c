#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_commands/my_functions.h"

// DONE
// ls
// cd
// rm
// rmdir
// mkdir
// tail
// free
// ps

void cmd_file_parse(FILE *file)
{
    char cmdline[1024];
    char *p, *cmds[256], *token;
    int cmd_cnt = 0;

    while (fgets(cmdline, 1024, file) != NULL) {
        fflush(file);
        if( (p = strstr(cmdline,"\n")) != NULL ) p[0] = 0;
        if (!strcmp(cmdline, "exit"))
            break;
        replace_env_var(cmdline);

        if (starts_with(cmdline, "if"))
            if_expression(cmdline);
        else {
            token = strtok(cmdline, "|");
            for (cmd_cnt = 0; token && cmd_cnt < 256; cmd_cnt++) {
                cmds[cmd_cnt] = strdup(token);
                token = strtok(NULL, "|");
            }
            cmds[cmd_cnt] = NULL;

            if (cmd_cnt > 0) {
                exec_conv(cmds, cmd_cnt, 0);
            }
        }
    }
}

// главная функция, цикл ввода строк (разбивка конвейера, запуск команды)
int main()
{
    char cmdline[1024];
    char *p, *cmds[256], *token;
    int cmd_cnt;

    shell_active = 1;

    while( shell_active )
    {
        printf("[%s]# ", getenv("PWD"));
        fflush(stdout);

        fgets(cmdline,1024,stdin);
        if( (p = strstr(cmdline,"\n")) != NULL ) p[0] = 0;

        if (starts_with(p, "./")) {
            char filename[256];
            strcpy(filename, p + 2);
            FILE *file = fopen(filename, "r");
            if (file != NULL) {
                cmd_file_parse(file);
                fclose(file);
            }
        }
        else {
            replace_env_var(cmdline);

            if (starts_with(cmdline, "if"))
                if_expression(cmdline);
            else {

                token = strtok(cmdline, "|");
                for (cmd_cnt = 0; token && cmd_cnt < 256; cmd_cnt++) {
                    cmds[cmd_cnt] = strdup(token);
                    token = strtok(NULL, "|");
                }
                cmds[cmd_cnt] = NULL;
                if (cmd_cnt > 0) {
                    exec_conv(cmds, cmd_cnt, 0);
                }
            }
        }
    }

    return 0;
}