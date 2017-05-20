//
// Created by murchanskii on 20.05.17.
//

// done !!!!!!!!

#include "my_functions.h"
#include <stdio.h>

SHCMD(free)
{
    int memTotal = 0, memFree = 0, memUsed = 0, memShared = 0, memBuffCache = 0, memAvailable = 0;
    int swapTotal = 0, swapUsed = 0, swapFree = 0;

    FILE *meminfo = fopen("/proc/meminfo", "r");
    int length = 30;
    char line[length];
    int end = 0;
    while (end == 0)
    {
        fgets(line, length, meminfo);
        if (starts_with(line, "MemTotal:"))
            memTotal = my_atoi(line);
        if (starts_with(line, "MemFree:"))
            memFree = my_atoi(line);
        if (starts_with(line, "MemAvailable:"))
            memAvailable = my_atoi(line);
        if (starts_with(line, "Buffers:"))
            memBuffCache += my_atoi(line);
        if (starts_with(line, "Cached:"))
            memBuffCache += my_atoi(line);
        if (starts_with(line, "SwapTotal:"))
            swapTotal = my_atoi(line);
        if (starts_with(line, "SwapFree:"))
            swapFree = my_atoi(line);
        if (starts_with(line, "Shmem:")) {
            memShared = my_atoi(line);
            end = 1;
        }
    }
    memUsed = memTotal - memFree - memBuffCache;
    swapUsed = swapTotal - swapFree;

    fclose(meminfo);

    printf("%10s%10s%10s%10s%10s%12s%10s\n","", "total", "used", "free", "shared", "buff/cache", "available");
    printf("%-10s%10d%10d%10d%10d%12d%10d\n", "Mem:", memTotal, memUsed, memFree, memShared, memBuffCache, memAvailable);
    printf("%-10s%10d%10d%10d\n", "Swap:", swapTotal, swapUsed, swapFree);

    return 0;
}