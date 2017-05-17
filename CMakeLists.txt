cmake_minimum_required(VERSION 3.7)
project(unixInd)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c my_commands/my_exit.c my_commands/my_functions.h my_commands/my_pwd.c my_commands/my_ls.c my_commands/my_cd.c my_commands/my_ps.c my_commands/my_rm.c my_commands/my_rmdir.c my_commands/my_mkdir.c)
add_executable(unixInd ${SOURCE_FILES})