//
// Created by murchanskii on 09.05.17.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <values.h>
#include "my_functions.h"

SHCMD(pwd)
{
    printf("%s\n",getenv("PWD"));
    return 0;
}