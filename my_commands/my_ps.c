//
// Created by murchanskii on 10.05.17.
//

// вывод списка процессов

#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctype.h>
#include <pwd.h>
#include <time.h>
#include <sys/types.h>
#include "my_functions.h"
#define PROC_FS "/proc"

struct dirent *entry;

typedef struct proc_t
{
    int pid;
    char cmd[256];
    unsigned char state;
    int ppid;
    int pgrp;
    int session;
    int tty_nr;
    int tpgid;
    uint flags;
    uint minflt;
    uint cminflt;
    uint majflt;
    uint cmajflt;
    int utime;
    int stime;
    int cutime;
    int cstime;
    int priority;
    uint nice;
    int zero;
    uint itrealvalue;
    int starttime;
    uint vsize;
    uint rss;
    uint rlim;
    uint startcode;
    uint endcode;
    uint startstack;
    uint kstkesp;
    uint kstkeip;
    int signal;
    int blocked;
    int sigignore;
    int sigcatch;
    uint wchan;
//additional
    int uid;
    time_t ctime;
} proc_t;

void read_proc_stat(struct proc_t *ps, char* fname)
{
    char path[256];

    struct stat st;

    sprintf(path,"/%s/%s/stat", PROC_FS, fname);

    FILE *file = fopen(path,"r");
    fscanf(file,"%d %s %c %d %d %d %d %u %u %u %u %u %d %d %d %d %d %u %d %u %d %u %u %u %u %u %u %u %u %d %d %d %u",
           &ps->pid, ps->cmd, &ps->state, &ps->ppid, &ps->pgrp, &ps->session,
           &ps->tty_nr, &ps->tpgid, &ps->flags, &ps->minflt, &ps->cminflt,
           &ps->majflt, &ps->cmajflt, &ps->utime, &ps->stime, &ps->cutime,
           &ps->cstime, &ps->priority, &ps->nice, &ps->zero, &ps->itrealvalue,
           &ps->starttime, &ps->vsize, &ps->rss, &ps->rlim, &ps->startcode,
           &ps->endcode, &ps->startstack, &ps->kstkesp, &ps->kstkeip, &ps->signal,
           &ps->blocked, &ps->sigignore, &ps->sigcatch, &ps->wchan
    );

    sprintf(path,"/%s/%s", PROC_FS, fname);
    lstat(path,&st);

    ps->uid = st.st_uid;
    ps->ctime = st.st_ctime;
    fclose(file);
}

SHCMD(ps)
{
    struct proc_t ps;

    DIR *Dir = opendir(PROC_FS);

    char time[256];

    printf("UID\t  PID  PPID  C\tSTIME\tTTY\tTIME\tCMD\n");
    while (entry = readdir(Dir)) {
        if(!isdigit(*entry->d_name))
            continue;
        read_proc_stat(&ps,entry->d_name);
        printf("%s\t",getpwuid(ps.uid)->pw_name);
        printf("%5d ",ps.pid);
        printf("%5d ",ps.ppid);
        printf("%2d\t",ps.nice);//?

        strftime(time, sizeof(time), "%H:%M", localtime(&ps.ctime));
        printf("%s\t",time);

        printf("\t");
        printf("\t");
        printf("%s\t",ps.cmd);
        printf("\n");
    }

    closedir(Dir);
    return 0;
}