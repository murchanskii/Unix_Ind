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

void initialisation(char *full_path, char *cur_param, int *i);
void getopt_for_dirs(int *flag_p, int *flag_v);
int is_regular_file(const char *path);
int starts_with (char *str, char *start);
void remove_certain_chars(char *str, char c);
int calc_n_start();

SHCMD(pwd);
SHCMD(exit);
SHCMD(ls);
SHCMD(cd);
SHCMD(ps);
SHCMD(rm);
SHCMD(rmdir);
SHCMD(mkdir);

#endif //UNIXIND_MY_FUNCTIONS_H
