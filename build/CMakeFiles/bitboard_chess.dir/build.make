# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\College_Stuff\C\bitboard-chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\College_Stuff\C\bitboard-chess\build

# Include any dependencies generated for this target.
include CMakeFiles/bitboard_chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bitboard_chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bitboard_chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bitboard_chess.dir/flags.make

CMakeFiles/bitboard_chess.dir/main.c.obj: CMakeFiles/bitboard_chess.dir/flags.make
CMakeFiles/bitboard_chess.dir/main.c.obj: D:/College_Stuff/C/bitboard-chess/main.c
CMakeFiles/bitboard_chess.dir/main.c.obj: CMakeFiles/bitboard_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\College_Stuff\C\bitboard-chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bitboard_chess.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bitboard_chess.dir/main.c.obj -MF CMakeFiles\bitboard_chess.dir\main.c.obj.d -o CMakeFiles\bitboard_chess.dir\main.c.obj -c D:\College_Stuff\C\bitboard-chess\main.c

CMakeFiles/bitboard_chess.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bitboard_chess.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\College_Stuff\C\bitboard-chess\main.c > CMakeFiles\bitboard_chess.dir\main.c.i

CMakeFiles/bitboard_chess.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bitboard_chess.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\College_Stuff\C\bitboard-chess\main.c -o CMakeFiles\bitboard_chess.dir\main.c.s

# Object files for target bitboard_chess
bitboard_chess_OBJECTS = \
"CMakeFiles/bitboard_chess.dir/main.c.obj"

# External object files for target bitboard_chess
bitboard_chess_EXTERNAL_OBJECTS =

bitboard_chess.exe: CMakeFiles/bitboard_chess.dir/main.c.obj
bitboard_chess.exe: CMakeFiles/bitboard_chess.dir/build.make
bitboard_chess.exe: CMakeFiles/bitboard_chess.dir/linkLibs.rsp
bitboard_chess.exe: CMakeFiles/bitboard_chess.dir/objects1.rsp
bitboard_chess.exe: CMakeFiles/bitboard_chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\College_Stuff\C\bitboard-chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bitboard_chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bitboard_chess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bitboard_chess.dir/build: bitboard_chess.exe
.PHONY : CMakeFiles/bitboard_chess.dir/build

CMakeFiles/bitboard_chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bitboard_chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bitboard_chess.dir/clean

CMakeFiles/bitboard_chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\College_Stuff\C\bitboard-chess D:\College_Stuff\C\bitboard-chess D:\College_Stuff\C\bitboard-chess\build D:\College_Stuff\C\bitboard-chess\build D:\College_Stuff\C\bitboard-chess\build\CMakeFiles\bitboard_chess.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/bitboard_chess.dir/depend

