# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas"

# Include any dependencies generated for this target.
include CMakeFiles/pruebapegado.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pruebapegado.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pruebapegado.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pruebapegado.dir/flags.make

CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.o: CMakeFiles/pruebapegado.dir/flags.make
CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.o: rutas_aereas/src/pruebapegado.cpp
CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.o: CMakeFiles/pruebapegado.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.o -MF CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.o.d -o CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.o -c "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas/rutas_aereas/src/pruebapegado.cpp"

CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas/rutas_aereas/src/pruebapegado.cpp" > CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.i

CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas/rutas_aereas/src/pruebapegado.cpp" -o CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.s

# Object files for target pruebapegado
pruebapegado_OBJECTS = \
"CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.o"

# External object files for target pruebapegado
pruebapegado_EXTERNAL_OBJECTS =

pruebapegado: CMakeFiles/pruebapegado.dir/rutas_aereas/src/pruebapegado.cpp.o
pruebapegado: CMakeFiles/pruebapegado.dir/build.make
pruebapegado: libimage.a
pruebapegado: CMakeFiles/pruebapegado.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pruebapegado"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pruebapegado.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pruebapegado.dir/build: pruebapegado
.PHONY : CMakeFiles/pruebapegado.dir/build

CMakeFiles/pruebapegado.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pruebapegado.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pruebapegado.dir/clean

CMakeFiles/pruebapegado.dir/depend:
	cd "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas" "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas" "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas" "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas" "/Users/martinhernandezruiz/Library/Mobile Documents/com~apple~CloudDocs/INGENIERIA INFORMÁTICA/SEGUNDO/ED/Rutas_Aereas/CMakeFiles/pruebapegado.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/pruebapegado.dir/depend

