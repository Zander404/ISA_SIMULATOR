# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\alexa\CLionProjects\ISA_SIMULATOR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\alexa\CLionProjects\ISA_SIMULATOR\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ISA_SIMULATOR.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ISA_SIMULATOR.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ISA_SIMULATOR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ISA_SIMULATOR.dir/flags.make

CMakeFiles/ISA_SIMULATOR.dir/main.c.obj: CMakeFiles/ISA_SIMULATOR.dir/flags.make
CMakeFiles/ISA_SIMULATOR.dir/main.c.obj: C:/Users/alexa/CLionProjects/ISA_SIMULATOR/main.c
CMakeFiles/ISA_SIMULATOR.dir/main.c.obj: CMakeFiles/ISA_SIMULATOR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\ISA_SIMULATOR\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ISA_SIMULATOR.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ISA_SIMULATOR.dir/main.c.obj -MF CMakeFiles\ISA_SIMULATOR.dir\main.c.obj.d -o CMakeFiles\ISA_SIMULATOR.dir\main.c.obj -c C:\Users\alexa\CLionProjects\ISA_SIMULATOR\main.c

CMakeFiles/ISA_SIMULATOR.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ISA_SIMULATOR.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\ISA_SIMULATOR\main.c > CMakeFiles\ISA_SIMULATOR.dir\main.c.i

CMakeFiles/ISA_SIMULATOR.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ISA_SIMULATOR.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\ISA_SIMULATOR\main.c -o CMakeFiles\ISA_SIMULATOR.dir\main.c.s

CMakeFiles/ISA_SIMULATOR.dir/teste.c.obj: CMakeFiles/ISA_SIMULATOR.dir/flags.make
CMakeFiles/ISA_SIMULATOR.dir/teste.c.obj: C:/Users/alexa/CLionProjects/ISA_SIMULATOR/teste.c
CMakeFiles/ISA_SIMULATOR.dir/teste.c.obj: CMakeFiles/ISA_SIMULATOR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\ISA_SIMULATOR\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ISA_SIMULATOR.dir/teste.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ISA_SIMULATOR.dir/teste.c.obj -MF CMakeFiles\ISA_SIMULATOR.dir\teste.c.obj.d -o CMakeFiles\ISA_SIMULATOR.dir\teste.c.obj -c C:\Users\alexa\CLionProjects\ISA_SIMULATOR\teste.c

CMakeFiles/ISA_SIMULATOR.dir/teste.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ISA_SIMULATOR.dir/teste.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\ISA_SIMULATOR\teste.c > CMakeFiles\ISA_SIMULATOR.dir\teste.c.i

CMakeFiles/ISA_SIMULATOR.dir/teste.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ISA_SIMULATOR.dir/teste.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\ISA_SIMULATOR\teste.c -o CMakeFiles\ISA_SIMULATOR.dir\teste.c.s

# Object files for target ISA_SIMULATOR
ISA_SIMULATOR_OBJECTS = \
"CMakeFiles/ISA_SIMULATOR.dir/main.c.obj" \
"CMakeFiles/ISA_SIMULATOR.dir/teste.c.obj"

# External object files for target ISA_SIMULATOR
ISA_SIMULATOR_EXTERNAL_OBJECTS =

ISA_SIMULATOR.exe: CMakeFiles/ISA_SIMULATOR.dir/main.c.obj
ISA_SIMULATOR.exe: CMakeFiles/ISA_SIMULATOR.dir/teste.c.obj
ISA_SIMULATOR.exe: CMakeFiles/ISA_SIMULATOR.dir/build.make
ISA_SIMULATOR.exe: CMakeFiles/ISA_SIMULATOR.dir/linkLibs.rsp
ISA_SIMULATOR.exe: CMakeFiles/ISA_SIMULATOR.dir/objects1
ISA_SIMULATOR.exe: CMakeFiles/ISA_SIMULATOR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\alexa\CLionProjects\ISA_SIMULATOR\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ISA_SIMULATOR.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ISA_SIMULATOR.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ISA_SIMULATOR.dir/build: ISA_SIMULATOR.exe
.PHONY : CMakeFiles/ISA_SIMULATOR.dir/build

CMakeFiles/ISA_SIMULATOR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ISA_SIMULATOR.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ISA_SIMULATOR.dir/clean

CMakeFiles/ISA_SIMULATOR.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\alexa\CLionProjects\ISA_SIMULATOR C:\Users\alexa\CLionProjects\ISA_SIMULATOR C:\Users\alexa\CLionProjects\ISA_SIMULATOR\cmake-build-debug C:\Users\alexa\CLionProjects\ISA_SIMULATOR\cmake-build-debug C:\Users\alexa\CLionProjects\ISA_SIMULATOR\cmake-build-debug\CMakeFiles\ISA_SIMULATOR.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ISA_SIMULATOR.dir/depend

