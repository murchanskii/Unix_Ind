//
// Created by murchanskii on 10.05.17.
//

// вывод списка процессов

#include "my_functions.h"
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

char itoa_str[15];
char pid_path[256];
char datetime[9];

char *itoa(int num)
{
    char revert_str[15];
    int i = 0;
    if (num == 0)
        revert_str[i++] = (char) (0 + '0');
    while (num > 0)
    {
        int last_char = num % 10;
        num /= 10;
        revert_str[i++] = (char) (last_char + '0');
    }
    revert_str[i] = 0;
    for (int j = 0; j < i; j++)
        itoa_str[j] = revert_str[i - 1 - j];
    itoa_str[i] = 0;
    return itoa_str;
}

char *get_pid_path(int pid)
{
    strcpy(pid_path, "/proc/");
    strcat(pid_path, itoa(pid));
    strcat(pid_path, "/stat");
    return pid_path;
}

void get_pid_info(char *path, int *pid, char *pname)
{
    FILE *proc = fopen(path, "r");
    fscanf(proc, "%d (%s)", pid, pname);
    pname[strlen(pname) - 1] = 0;
    fclose(proc);
}

void get_time_info(char *path, long *seconds)
{
    FILE *proc = fopen(path, "r");
    int k;
    long j;
    char p[10];

    fscanf(proc, "%d %s %c %d %d %d %d %d %lu %lu %lu %lu %lu %lu",
           &k, p, p, &k, &k, &k, &k, &k, &j, &j, &j, &j, &j, &j);

    *seconds = j / sysconf(_SC_CLK_TCK);
    fclose(proc);
}

char *convert_to_datetime(int secs)
{
    int mins = 0, hrs = 0;
    mins = secs / 60;
    hrs = mins / 60;
    secs %= 60;
    mins %= 60;
    if (hrs < 10) {
        strcpy(datetime, "0");
        strcat(datetime, itoa(hrs));
    }
    else
        strcpy(datetime, itoa(hrs));
    strcat(datetime, ":");
    if (mins < 10)
        strcat(datetime, "0");
    strcat(datetime, itoa(mins));
    strcat(datetime, ":");
    if (secs < 10)
        strcat(datetime, "0");
    strcat(datetime, itoa(secs));
    return datetime;
}

void print_ps(int PID)
{
    char PID_path[256];
    strcpy(PID_path, get_pid_path(PID));

    char p_name[50];
    get_pid_info(PID_path, &PID, p_name);

    long p_time;
    get_time_info(PID_path, &p_time);

    printf("%5d %-8s %8s %s\n", PID, ttyname(0) + 5, convert_to_datetime(p_time), p_name);
}

SHCMD(ps)
{
    printf("%5s %-8s %8s %s\n", "PID", "TTY", "TIME", "CMD");
    print_ps(getppid());
    print_ps(getpid());

    return 0;
}