# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ex11.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ex11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex11.dir/flags.make

CMakeFiles/ex11.dir/ex11.c.obj: CMakeFiles/ex11.dir/flags.make
CMakeFiles/ex11.dir/ex11.c.obj: C:/Users/footr/OneDrive/Documentos/Uni/P/Pratica/Ficha4/ex11.c
CMakeFiles/ex11.dir/ex11.c.obj: CMakeFiles/ex11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ex11.dir/ex11.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ex11.dir/ex11.c.obj -MF CMakeFiles\ex11.dir\ex11.c.obj.d -o CMakeFiles\ex11.dir\ex11.c.obj -c C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4\ex11.c

CMakeFiles/ex11.dir/ex11.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ex11.dir/ex11.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4\ex11.c > CMakeFiles\ex11.dir\ex11.c.i

CMakeFiles/ex11.dir/ex11.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ex11.dir/ex11.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4\ex11.c -o CMakeFiles\ex11.dir\ex11.c.s

# Object files for target ex11
ex11_OBJECTS = \
"CMakeFiles/ex11.dir/ex11.c.obj"

# External object files for target ex11
ex11_EXTERNAL_OBJECTS =

ex11.exe: CMakeFiles/ex11.dir/ex11.c.obj
ex11.exe: CMakeFiles/ex11.dir/build.make
ex11.exe: CMakeFiles/ex11.dir/linkLibs.rsp
ex11.exe: CMakeFiles/ex11.dir/objects1.rsp
ex11.exe: CMakeFiles/ex11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ex11.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex11.dir/build: ex11.exe
.PHONY : CMakeFiles/ex11.dir/build

CMakeFiles/ex11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex11.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex11.dir/clean

CMakeFiles/ex11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4 C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4 C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4\cmake-build-debug C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4\cmake-build-debug C:\Users\footr\OneDrive\Documentos\Uni\P\Pratica\Ficha4\cmake-build-debug\CMakeFiles\ex11.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ex11.dir/depend

