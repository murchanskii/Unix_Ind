//
// Created by murchanskii on 10.05.17.
//

// вывод списка процессов
// -e -a -f - сделать

#include "my_functions.h"
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>

char itoa_str[15];
char datetime[9];

struct proc_stat
{
    int pid;
    char tcomm[128];
    char state;
    int ppid;
    int pgid;
    int sid;
    int tty_nr;
    int tty_pgrp;
    long flags;
    long min_flt;
    long cmin_flt;
    long maj_flt;
    long cmaj_flt;
    int utime;
    int stime;
    int cutime;
    int cstime;
    int priority;
    int nice;
    int num_threads;
    long it_real_value;
    long start_time;
    long vsize;
    long rss;
    long rsslim;
    long start_code;
    long end_code;
    long start_stack;
    long esp;
    long eip;
    long pending;
    long smth;
    long sigign;
    long sigcatch;
    long wchan;
    int zero1;
    int zero2;
    long exit_signal;
    int cpu;
    int rt_priority;
    int policy;
    int uid;
    int c;
    int s_time;
} stats;

struct stat st1;
int all_time;

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

void get_stats(int PID)
{
    char path[128];
    strcpy(path, "/proc/");
    strcat(path, itoa(PID));
    strcat(path, "/stat");
    FILE *proc = fopen(path, "r");
    fscanf(proc, "%d %s %c %d %d %d %d %d %lu %lu %lu %lu %lu %d %d %d %d %d %d %d %lu %lu"
                   "%lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %d %d %lu %d %d %d",
           &stats.pid, stats.tcomm, &stats.state, &stats.ppid,
           &stats.pgid, &stats.sid, &stats.tty_nr, &stats.tty_pgrp,
           &stats.flags, &stats.min_flt, &stats.cmin_flt, &stats.maj_flt,
           &stats.cmaj_flt, &stats.utime, &stats.stime, &stats.cutime, &stats.cstime,
           &stats.priority, &stats.nice, &stats.num_threads, &stats.it_real_value,
           &stats.start_time, &stats.vsize, &stats.rss, &stats.rsslim, &stats.start_code,
           &stats.end_code, &stats.start_stack, &stats.esp, &stats.eip, &stats.pending,
           &stats.smth, &stats.sigign, &stats.sigcatch, &stats.wchan, &stats.zero1,
           &stats.zero2, &stats.exit_signal, &stats.cpu, &stats.rt_priority, &stats.policy);
    fclose(proc);
    lstat(path, &st1);

    stats.uid = st1.st_uid;
    all_time = stats.utime + stats.stime + stats.cutime + stats.cstime;
    int proc_time;
    proc = fopen("/proc/uptime", "r");
    fscanf(proc, "%d", &proc_time);
    fclose(proc);
    proc_time *= sysconf(_SC_CLK_TCK);
    proc_time -= stats.start_time;
    stats.c = 100 * all_time/proc_time;

    strcpy(path, "/proc/");
    strcat(path, itoa(PID));
    strcat(path, "/cmdline");
    int fd = open(path, O_RDONLY);
    read(fd, stats.tcomm, sizeof(stats.tcomm));
    close(fd);
}

struct passwd *pwd;

char *convert_to_datetime(int secs)
{
    int t = secs;
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
    get_stats(PID);
    char *UID = getpwuid(stats.uid)->pw_name;
    int PPID = stats.ppid;
    int C = stats.c;
    int time = (stats.utime + stats.stime) / sysconf(_SC_CLK_TCK);
    char *CMD = stats.tcomm;

    char STIME[80];
    strftime(STIME, sizeof(STIME), "%H:%M", localtime((const time_t *) &st1.st_mtim));

    printf("%-7.7s %-5d %-5d %-2d %-6s %-8s %8s %s\n", UID, PID, PPID, C,
           STIME,
           ttyname(0) + 5, convert_to_datetime(time), CMD);
}

int filter_ps (const struct dirent *d)
{
    if (atoi(d->d_name) > 0)    // all is ok
        return 1;
    return 0;
}

SHCMD(ps)
{
    printf("%7s %-5s %-5s %-2s %-6s %-8s %8s %s\n", "UID", "PID", "PPID", "C", "STIME", "TTY", "TIME", "CMD");
    struct dirent **entry;
    opendir("/proc");
    int n = scandir("/proc", &entry, filter_ps, NULL);
    for (int i = 0; i < n; i++)
        print_ps(atoi(entry[i]->d_name));


    for (int  i = 0; i < n; i++)
        free(entry[i]);
    free(entry);

    return 0;
}
