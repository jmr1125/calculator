# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jiang/Desktop/calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jiang/Desktop/calculator/build

# Include any dependencies generated for this target.
include CMakeFiles/genpdf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/genpdf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/genpdf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/genpdf.dir/flags.make

CMakeFiles/genpdf.dir/genpdf.cpp.o: CMakeFiles/genpdf.dir/flags.make
CMakeFiles/genpdf.dir/genpdf.cpp.o: /Users/jiang/Desktop/calculator/genpdf.cpp
CMakeFiles/genpdf.dir/genpdf.cpp.o: CMakeFiles/genpdf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiang/Desktop/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/genpdf.dir/genpdf.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/genpdf.dir/genpdf.cpp.o -MF CMakeFiles/genpdf.dir/genpdf.cpp.o.d -o CMakeFiles/genpdf.dir/genpdf.cpp.o -c /Users/jiang/Desktop/calculator/genpdf.cpp

CMakeFiles/genpdf.dir/genpdf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/genpdf.dir/genpdf.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jiang/Desktop/calculator/genpdf.cpp > CMakeFiles/genpdf.dir/genpdf.cpp.i

CMakeFiles/genpdf.dir/genpdf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/genpdf.dir/genpdf.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jiang/Desktop/calculator/genpdf.cpp -o CMakeFiles/genpdf.dir/genpdf.cpp.s

# Object files for target genpdf
genpdf_OBJECTS = \
"CMakeFiles/genpdf.dir/genpdf.cpp.o"

# External object files for target genpdf
genpdf_EXTERNAL_OBJECTS =

libgenpdf.a: CMakeFiles/genpdf.dir/genpdf.cpp.o
libgenpdf.a: CMakeFiles/genpdf.dir/build.make
libgenpdf.a: CMakeFiles/genpdf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jiang/Desktop/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgenpdf.a"
	$(CMAKE_COMMAND) -P CMakeFiles/genpdf.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/genpdf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/genpdf.dir/build: libgenpdf.a
.PHONY : CMakeFiles/genpdf.dir/build

CMakeFiles/genpdf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/genpdf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/genpdf.dir/clean

CMakeFiles/genpdf.dir/depend:
	cd /Users/jiang/Desktop/calculator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jiang/Desktop/calculator /Users/jiang/Desktop/calculator /Users/jiang/Desktop/calculator/build /Users/jiang/Desktop/calculator/build /Users/jiang/Desktop/calculator/build/CMakeFiles/genpdf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/genpdf.dir/depend

