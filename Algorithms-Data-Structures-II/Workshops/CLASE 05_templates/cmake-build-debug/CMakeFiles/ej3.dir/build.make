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
CMAKE_SOURCE_DIR = "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ej3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej3.dir/flags.make

CMakeFiles/ej3.dir/tests/test_templates.cpp.o: CMakeFiles/ej3.dir/flags.make
CMakeFiles/ej3.dir/tests/test_templates.cpp.o: ../tests/test_templates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej3.dir/tests/test_templates.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej3.dir/tests/test_templates.cpp.o -c "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/tests/test_templates.cpp"

CMakeFiles/ej3.dir/tests/test_templates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej3.dir/tests/test_templates.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/tests/test_templates.cpp" > CMakeFiles/ej3.dir/tests/test_templates.cpp.i

CMakeFiles/ej3.dir/tests/test_templates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej3.dir/tests/test_templates.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/tests/test_templates.cpp" -o CMakeFiles/ej3.dir/tests/test_templates.cpp.s

# Object files for target ej3
ej3_OBJECTS = \
"CMakeFiles/ej3.dir/tests/test_templates.cpp.o"

# External object files for target ej3
ej3_EXTERNAL_OBJECTS =

ej3: CMakeFiles/ej3.dir/tests/test_templates.cpp.o
ej3: CMakeFiles/ej3.dir/build.make
ej3: libgtest.a
ej3: libgtest_main.a
ej3: CMakeFiles/ej3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej3.dir/build: ej3

.PHONY : CMakeFiles/ej3.dir/build

CMakeFiles/ej3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej3.dir/clean

CMakeFiles/ej3.dir/depend:
	cd "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates" "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates" "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/cmake-build-debug" "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/cmake-build-debug" "/home/daredevil/UBA/ALGOS2/tallerAlgoritmos2/CLASE 05_templates/cmake-build-debug/CMakeFiles/ej3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ej3.dir/depend

