# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/martinhdzruiz/Escritorio/Rutas_Aereas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/martinhdzruiz/Escritorio/Rutas_Aereas

# Include any dependencies generated for this target.
include CMakeFiles/pruebarotacion.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pruebarotacion.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pruebarotacion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pruebarotacion.dir/flags.make

CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.o: CMakeFiles/pruebarotacion.dir/flags.make
CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.o: rutas_aereas/src/pruebarotacion.cpp
CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.o: CMakeFiles/pruebarotacion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martinhdzruiz/Escritorio/Rutas_Aereas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.o -MF CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.o.d -o CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.o -c /home/martinhdzruiz/Escritorio/Rutas_Aereas/rutas_aereas/src/pruebarotacion.cpp

CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martinhdzruiz/Escritorio/Rutas_Aereas/rutas_aereas/src/pruebarotacion.cpp > CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.i

CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martinhdzruiz/Escritorio/Rutas_Aereas/rutas_aereas/src/pruebarotacion.cpp -o CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.s

# Object files for target pruebarotacion
pruebarotacion_OBJECTS = \
"CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.o"

# External object files for target pruebarotacion
pruebarotacion_EXTERNAL_OBJECTS =

pruebarotacion: CMakeFiles/pruebarotacion.dir/rutas_aereas/src/pruebarotacion.cpp.o
pruebarotacion: CMakeFiles/pruebarotacion.dir/build.make
pruebarotacion: libimage.a
pruebarotacion: CMakeFiles/pruebarotacion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martinhdzruiz/Escritorio/Rutas_Aereas/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pruebarotacion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pruebarotacion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pruebarotacion.dir/build: pruebarotacion
.PHONY : CMakeFiles/pruebarotacion.dir/build

CMakeFiles/pruebarotacion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pruebarotacion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pruebarotacion.dir/clean

CMakeFiles/pruebarotacion.dir/depend:
	cd /home/martinhdzruiz/Escritorio/Rutas_Aereas && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martinhdzruiz/Escritorio/Rutas_Aereas /home/martinhdzruiz/Escritorio/Rutas_Aereas /home/martinhdzruiz/Escritorio/Rutas_Aereas /home/martinhdzruiz/Escritorio/Rutas_Aereas /home/martinhdzruiz/Escritorio/Rutas_Aereas/CMakeFiles/pruebarotacion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pruebarotacion.dir/depend

