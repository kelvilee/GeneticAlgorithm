# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kelvin/CLionProjects/GeneticAlgorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kelvin/CLionProjects/GeneticAlgorithm/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GeneticAlgorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GeneticAlgorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GeneticAlgorithm.dir/flags.make

CMakeFiles/GeneticAlgorithm.dir/main.cpp.o: CMakeFiles/GeneticAlgorithm.dir/flags.make
CMakeFiles/GeneticAlgorithm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kelvin/CLionProjects/GeneticAlgorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GeneticAlgorithm.dir/main.cpp.o"
	/Library/Developer/CommandLinetools/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GeneticAlgorithm.dir/main.cpp.o -c /Users/kelvin/CLionProjects/GeneticAlgorithm/main.cpp

CMakeFiles/GeneticAlgorithm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GeneticAlgorithm.dir/main.cpp.i"
	/Library/Developer/CommandLinetools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kelvin/CLionProjects/GeneticAlgorithm/main.cpp > CMakeFiles/GeneticAlgorithm.dir/main.cpp.i

CMakeFiles/GeneticAlgorithm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GeneticAlgorithm.dir/main.cpp.s"
	/Library/Developer/CommandLinetools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kelvin/CLionProjects/GeneticAlgorithm/main.cpp -o CMakeFiles/GeneticAlgorithm.dir/main.cpp.s

# Object files for target GeneticAlgorithm
GeneticAlgorithm_OBJECTS = \
"CMakeFiles/GeneticAlgorithm.dir/main.cpp.o"

# External object files for target GeneticAlgorithm
GeneticAlgorithm_EXTERNAL_OBJECTS =

GeneticAlgorithm: CMakeFiles/GeneticAlgorithm.dir/main.cpp.o
GeneticAlgorithm: CMakeFiles/GeneticAlgorithm.dir/build.make
GeneticAlgorithm: CMakeFiles/GeneticAlgorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kelvin/CLionProjects/GeneticAlgorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GeneticAlgorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GeneticAlgorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GeneticAlgorithm.dir/build: GeneticAlgorithm

.PHONY : CMakeFiles/GeneticAlgorithm.dir/build

CMakeFiles/GeneticAlgorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GeneticAlgorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GeneticAlgorithm.dir/clean

CMakeFiles/GeneticAlgorithm.dir/depend:
	cd /Users/kelvin/CLionProjects/GeneticAlgorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kelvin/CLionProjects/GeneticAlgorithm /Users/kelvin/CLionProjects/GeneticAlgorithm /Users/kelvin/CLionProjects/GeneticAlgorithm/cmake-build-debug /Users/kelvin/CLionProjects/GeneticAlgorithm/cmake-build-debug /Users/kelvin/CLionProjects/GeneticAlgorithm/cmake-build-debug/CMakeFiles/GeneticAlgorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GeneticAlgorithm.dir/depend
