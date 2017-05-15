//
// Created by murchanskii on 09.05.17.
//

#ifndef UNIXIND_MY_FUNCTIONS_H
#define UNIXIND_MY_FUNCTIONS_H

#define SHCMD(x) int shcmd_##x (char* cmd, char* params[])
#define SHCMD_EXEC(x) shcmd_##x (params[0], params)
#define IS_CMD(x) strncmp(#x,cmd,strlen(cmd)) == 0

int shell_active;
int np; // number of parameters
char *params[256]; //параметры команды разделенные пробелами

int starts_with (char *str, char *start);
int is_regular_file(const char *path);
int file_exists(char *filename, char *path);
void to_one_string(int n_start, char *filename, char **params);

SHCMD(pwd);
SHCMD(exit);
SHCMD(ls);
SHCMD(cd);
SHCMD(ps);
SHCMD(rm);
SHCMD(rmdir);

#endif //UNIXIND_MY_FUNCTIONS_H
