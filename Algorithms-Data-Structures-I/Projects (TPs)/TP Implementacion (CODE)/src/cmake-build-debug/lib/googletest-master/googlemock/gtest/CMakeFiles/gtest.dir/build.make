# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/daredevil/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6183.77/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/daredevil/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6183.77/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug

# Include any dependencies generated for this target.
include lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../lib/googletest-master/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/lib/googletest-master/googlemock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/lib/googletest-master/googletest/src/gtest-all.cc

lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/lib/googletest-master/googlemock/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/lib/googletest-master/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/lib/googletest-master/googlemock/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/lib/googletest-master/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/googletest-master/googlemock/gtest/libgtestd.a: lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/googletest-master/googlemock/gtest/libgtestd.a: lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/build.make
lib/googletest-master/googlemock/gtest/libgtestd.a: lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtestd.a"
	cd /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/lib/googletest-master/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/lib/googletest-master/googlemock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/build: lib/googletest-master/googlemock/gtest/libgtestd.a

.PHONY : lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/build

lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/lib/googletest-master/googlemock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/clean

lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	cd /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/lib/googletest-master/googletest /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/lib/googletest-master/googlemock/gtest /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/googletest-master/googlemock/gtest/CMakeFiles/gtest.dir/depend

