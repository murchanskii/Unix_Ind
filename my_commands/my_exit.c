//
// Created by murchanskii on 09.05.17.
//

#include <stdio.h>
#include "my_functions.h"

SHCMD(exit)
{
    shell_active = 0;
    printf("Bye, bye!\n");
    return 0;
}