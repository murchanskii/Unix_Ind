# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/murchanskii/Downloads/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/murchanskii/Downloads/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/murchanskii/Documents/my_unix_ind

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/murchanskii/Documents/my_unix_ind/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/unixInd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unixInd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unixInd.dir/flags.make

CMakeFiles/unixInd.dir/main.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/unixInd.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/main.c.o   -c /home/murchanskii/Documents/my_unix_ind/main.c

CMakeFiles/unixInd.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/main.c > CMakeFiles/unixInd.dir/main.c.i

CMakeFiles/unixInd.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/main.c -o CMakeFiles/unixInd.dir/main.c.s

CMakeFiles/unixInd.dir/main.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/main.c.o.requires

CMakeFiles/unixInd.dir/main.c.o.provides: CMakeFiles/unixInd.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/main.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/main.c.o.provides

CMakeFiles/unixInd.dir/main.c.o.provides.build: CMakeFiles/unixInd.dir/main.c.o


CMakeFiles/unixInd.dir/my_commands/my_exit.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/my_exit.c.o: ../my_commands/my_exit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/unixInd.dir/my_commands/my_exit.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/my_exit.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/my_exit.c

CMakeFiles/unixInd.dir/my_commands/my_exit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/my_exit.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/my_exit.c > CMakeFiles/unixInd.dir/my_commands/my_exit.c.i

CMakeFiles/unixInd.dir/my_commands/my_exit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/my_exit.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/my_exit.c -o CMakeFiles/unixInd.dir/my_commands/my_exit.c.s

CMakeFiles/unixInd.dir/my_commands/my_exit.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/my_exit.c.o.requires

CMakeFiles/unixInd.dir/my_commands/my_exit.c.o.provides: CMakeFiles/unixInd.dir/my_commands/my_exit.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/my_exit.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/my_exit.c.o.provides

CMakeFiles/unixInd.dir/my_commands/my_exit.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/my_exit.c.o


CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o: ../my_commands/my_pwd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/my_pwd.c

CMakeFiles/unixInd.dir/my_commands/my_pwd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/my_pwd.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/my_pwd.c > CMakeFiles/unixInd.dir/my_commands/my_pwd.c.i

CMakeFiles/unixInd.dir/my_commands/my_pwd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/my_pwd.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/my_pwd.c -o CMakeFiles/unixInd.dir/my_commands/my_pwd.c.s

CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o.requires

CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o.provides: CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o.provides

CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o


CMakeFiles/unixInd.dir/my_commands/my_ls.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/my_ls.c.o: ../my_commands/my_ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/unixInd.dir/my_commands/my_ls.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/my_ls.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/my_ls.c

CMakeFiles/unixInd.dir/my_commands/my_ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/my_ls.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/my_ls.c > CMakeFiles/unixInd.dir/my_commands/my_ls.c.i

CMakeFiles/unixInd.dir/my_commands/my_ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/my_ls.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/my_ls.c -o CMakeFiles/unixInd.dir/my_commands/my_ls.c.s

CMakeFiles/unixInd.dir/my_commands/my_ls.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/my_ls.c.o.requires

CMakeFiles/unixInd.dir/my_commands/my_ls.c.o.provides: CMakeFiles/unixInd.dir/my_commands/my_ls.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/my_ls.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/my_ls.c.o.provides

CMakeFiles/unixInd.dir/my_commands/my_ls.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/my_ls.c.o


CMakeFiles/unixInd.dir/my_commands/my_cd.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/my_cd.c.o: ../my_commands/my_cd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/unixInd.dir/my_commands/my_cd.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/my_cd.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/my_cd.c

CMakeFiles/unixInd.dir/my_commands/my_cd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/my_cd.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/my_cd.c > CMakeFiles/unixInd.dir/my_commands/my_cd.c.i

CMakeFiles/unixInd.dir/my_commands/my_cd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/my_cd.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/my_cd.c -o CMakeFiles/unixInd.dir/my_commands/my_cd.c.s

CMakeFiles/unixInd.dir/my_commands/my_cd.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/my_cd.c.o.requires

CMakeFiles/unixInd.dir/my_commands/my_cd.c.o.provides: CMakeFiles/unixInd.dir/my_commands/my_cd.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/my_cd.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/my_cd.c.o.provides

CMakeFiles/unixInd.dir/my_commands/my_cd.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/my_cd.c.o


CMakeFiles/unixInd.dir/my_commands/my_ps.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/my_ps.c.o: ../my_commands/my_ps.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/unixInd.dir/my_commands/my_ps.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/my_ps.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/my_ps.c

CMakeFiles/unixInd.dir/my_commands/my_ps.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/my_ps.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/my_ps.c > CMakeFiles/unixInd.dir/my_commands/my_ps.c.i

CMakeFiles/unixInd.dir/my_commands/my_ps.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/my_ps.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/my_ps.c -o CMakeFiles/unixInd.dir/my_commands/my_ps.c.s

CMakeFiles/unixInd.dir/my_commands/my_ps.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/my_ps.c.o.requires

CMakeFiles/unixInd.dir/my_commands/my_ps.c.o.provides: CMakeFiles/unixInd.dir/my_commands/my_ps.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/my_ps.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/my_ps.c.o.provides

CMakeFiles/unixInd.dir/my_commands/my_ps.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/my_ps.c.o


CMakeFiles/unixInd.dir/my_commands/my_rm.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/my_rm.c.o: ../my_commands/my_rm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/unixInd.dir/my_commands/my_rm.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/my_rm.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/my_rm.c

CMakeFiles/unixInd.dir/my_commands/my_rm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/my_rm.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/my_rm.c > CMakeFiles/unixInd.dir/my_commands/my_rm.c.i

CMakeFiles/unixInd.dir/my_commands/my_rm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/my_rm.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/my_rm.c -o CMakeFiles/unixInd.dir/my_commands/my_rm.c.s

CMakeFiles/unixInd.dir/my_commands/my_rm.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/my_rm.c.o.requires

CMakeFiles/unixInd.dir/my_commands/my_rm.c.o.provides: CMakeFiles/unixInd.dir/my_commands/my_rm.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/my_rm.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/my_rm.c.o.provides

CMakeFiles/unixInd.dir/my_commands/my_rm.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/my_rm.c.o


CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o: ../my_commands/my_mkdir.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/my_mkdir.c

CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/my_mkdir.c > CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.i

CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/my_mkdir.c -o CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.s

CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o.requires

CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o.provides: CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o.provides

CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o


CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o: ../my_commands/my_rmdir.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/my_rmdir.c

CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/my_rmdir.c > CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.i

CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/my_rmdir.c -o CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.s

CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o.requires

CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o.provides: CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o.provides

CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o


CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o: ../my_commands/additional_funcs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/additional_funcs.c

CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/additional_funcs.c > CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.i

CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/additional_funcs.c -o CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.s

CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o.requires

CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o.provides: CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o.provides

CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o


CMakeFiles/unixInd.dir/my_commands/my_tail.c.o: CMakeFiles/unixInd.dir/flags.make
CMakeFiles/unixInd.dir/my_commands/my_tail.c.o: ../my_commands/my_tail.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/unixInd.dir/my_commands/my_tail.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unixInd.dir/my_commands/my_tail.c.o   -c /home/murchanskii/Documents/my_unix_ind/my_commands/my_tail.c

CMakeFiles/unixInd.dir/my_commands/my_tail.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unixInd.dir/my_commands/my_tail.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/murchanskii/Documents/my_unix_ind/my_commands/my_tail.c > CMakeFiles/unixInd.dir/my_commands/my_tail.c.i

CMakeFiles/unixInd.dir/my_commands/my_tail.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unixInd.dir/my_commands/my_tail.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/murchanskii/Documents/my_unix_ind/my_commands/my_tail.c -o CMakeFiles/unixInd.dir/my_commands/my_tail.c.s

CMakeFiles/unixInd.dir/my_commands/my_tail.c.o.requires:

.PHONY : CMakeFiles/unixInd.dir/my_commands/my_tail.c.o.requires

CMakeFiles/unixInd.dir/my_commands/my_tail.c.o.provides: CMakeFiles/unixInd.dir/my_commands/my_tail.c.o.requires
	$(MAKE) -f CMakeFiles/unixInd.dir/build.make CMakeFiles/unixInd.dir/my_commands/my_tail.c.o.provides.build
.PHONY : CMakeFiles/unixInd.dir/my_commands/my_tail.c.o.provides

CMakeFiles/unixInd.dir/my_commands/my_tail.c.o.provides.build: CMakeFiles/unixInd.dir/my_commands/my_tail.c.o


# Object files for target unixInd
unixInd_OBJECTS = \
"CMakeFiles/unixInd.dir/main.c.o" \
"CMakeFiles/unixInd.dir/my_commands/my_exit.c.o" \
"CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o" \
"CMakeFiles/unixInd.dir/my_commands/my_ls.c.o" \
"CMakeFiles/unixInd.dir/my_commands/my_cd.c.o" \
"CMakeFiles/unixInd.dir/my_commands/my_ps.c.o" \
"CMakeFiles/unixInd.dir/my_commands/my_rm.c.o" \
"CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o" \
"CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o" \
"CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o" \
"CMakeFiles/unixInd.dir/my_commands/my_tail.c.o"

# External object files for target unixInd
unixInd_EXTERNAL_OBJECTS =

unixInd: CMakeFiles/unixInd.dir/main.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/my_exit.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/my_ls.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/my_cd.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/my_ps.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/my_rm.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o
unixInd: CMakeFiles/unixInd.dir/my_commands/my_tail.c.o
unixInd: CMakeFiles/unixInd.dir/build.make
unixInd: CMakeFiles/unixInd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable unixInd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unixInd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unixInd.dir/build: unixInd

.PHONY : CMakeFiles/unixInd.dir/build

CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/main.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/my_exit.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/my_pwd.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/my_ls.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/my_cd.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/my_ps.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/my_rm.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/my_mkdir.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/my_rmdir.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/additional_funcs.c.o.requires
CMakeFiles/unixInd.dir/requires: CMakeFiles/unixInd.dir/my_commands/my_tail.c.o.requires

.PHONY : CMakeFiles/unixInd.dir/requires

CMakeFiles/unixInd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unixInd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unixInd.dir/clean

CMakeFiles/unixInd.dir/depend:
	cd /home/murchanskii/Documents/my_unix_ind/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/murchanskii/Documents/my_unix_ind /home/murchanskii/Documents/my_unix_ind /home/murchanskii/Documents/my_unix_ind/cmake-build-debug /home/murchanskii/Documents/my_unix_ind/cmake-build-debug /home/murchanskii/Documents/my_unix_ind/cmake-build-debug/CMakeFiles/unixInd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unixInd.dir/depend

