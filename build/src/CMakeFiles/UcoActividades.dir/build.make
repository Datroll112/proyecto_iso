# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/Escritorio/proyecto_iso

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/Escritorio/proyecto_iso/build

# Include any dependencies generated for this target.
include src/CMakeFiles/UcoActividades.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/UcoActividades.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/UcoActividades.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/UcoActividades.dir/flags.make

src/CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.o: src/CMakeFiles/UcoActividades.dir/flags.make
src/CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.o: ../src/UcoActividades-Funciones.cc
src/CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.o: src/CMakeFiles/UcoActividades.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Escritorio/proyecto_iso/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.o"
	cd /home/david/Escritorio/proyecto_iso/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.o -MF CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.o.d -o CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.o -c /home/david/Escritorio/proyecto_iso/src/UcoActividades-Funciones.cc

src/CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.i"
	cd /home/david/Escritorio/proyecto_iso/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Escritorio/proyecto_iso/src/UcoActividades-Funciones.cc > CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.i

src/CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.s"
	cd /home/david/Escritorio/proyecto_iso/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Escritorio/proyecto_iso/src/UcoActividades-Funciones.cc -o CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.s

# Object files for target UcoActividades
UcoActividades_OBJECTS = \
"CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.o"

# External object files for target UcoActividades
UcoActividades_EXTERNAL_OBJECTS =

src/libUcoActividades.a: src/CMakeFiles/UcoActividades.dir/UcoActividades-Funciones.cc.o
src/libUcoActividades.a: src/CMakeFiles/UcoActividades.dir/build.make
src/libUcoActividades.a: src/CMakeFiles/UcoActividades.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/Escritorio/proyecto_iso/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUcoActividades.a"
	cd /home/david/Escritorio/proyecto_iso/build/src && $(CMAKE_COMMAND) -P CMakeFiles/UcoActividades.dir/cmake_clean_target.cmake
	cd /home/david/Escritorio/proyecto_iso/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UcoActividades.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/UcoActividades.dir/build: src/libUcoActividades.a
.PHONY : src/CMakeFiles/UcoActividades.dir/build

src/CMakeFiles/UcoActividades.dir/clean:
	cd /home/david/Escritorio/proyecto_iso/build/src && $(CMAKE_COMMAND) -P CMakeFiles/UcoActividades.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/UcoActividades.dir/clean

src/CMakeFiles/UcoActividades.dir/depend:
	cd /home/david/Escritorio/proyecto_iso/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/Escritorio/proyecto_iso /home/david/Escritorio/proyecto_iso/src /home/david/Escritorio/proyecto_iso/build /home/david/Escritorio/proyecto_iso/build/src /home/david/Escritorio/proyecto_iso/build/src/CMakeFiles/UcoActividades.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/UcoActividades.dir/depend

