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
include CMakeFiles/analisisHabitacional.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/analisisHabitacional.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/analisisHabitacional.dir/flags.make

CMakeFiles/analisisHabitacional.dir/main.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/main.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/analisisHabitacional.dir/main.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/main.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/main.cpp

CMakeFiles/analisisHabitacional.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/main.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/main.cpp > CMakeFiles/analisisHabitacional.dir/main.i

CMakeFiles/analisisHabitacional.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/main.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/main.cpp -o CMakeFiles/analisisHabitacional.dir/main.s

CMakeFiles/analisisHabitacional.dir/auxiliares.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/auxiliares.o: ../auxiliares.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/analisisHabitacional.dir/auxiliares.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/auxiliares.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/auxiliares.cpp

CMakeFiles/analisisHabitacional.dir/auxiliares.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/auxiliares.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/auxiliares.cpp > CMakeFiles/analisisHabitacional.dir/auxiliares.i

CMakeFiles/analisisHabitacional.dir/auxiliares.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/auxiliares.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/auxiliares.cpp -o CMakeFiles/analisisHabitacional.dir/auxiliares.s

CMakeFiles/analisisHabitacional.dir/ejercicios.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/ejercicios.o: ../ejercicios.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/analisisHabitacional.dir/ejercicios.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/ejercicios.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/ejercicios.cpp

CMakeFiles/analisisHabitacional.dir/ejercicios.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/ejercicios.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/ejercicios.cpp > CMakeFiles/analisisHabitacional.dir/ejercicios.i

CMakeFiles/analisisHabitacional.dir/ejercicios.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/ejercicios.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/ejercicios.cpp -o CMakeFiles/analisisHabitacional.dir/ejercicios.s

CMakeFiles/analisisHabitacional.dir/Funciones_TPI.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/Funciones_TPI.o: ../Funciones_TPI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/analisisHabitacional.dir/Funciones_TPI.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/Funciones_TPI.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/Funciones_TPI.cpp

CMakeFiles/analisisHabitacional.dir/Funciones_TPI.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/Funciones_TPI.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/Funciones_TPI.cpp > CMakeFiles/analisisHabitacional.dir/Funciones_TPI.i

CMakeFiles/analisisHabitacional.dir/Funciones_TPI.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/Funciones_TPI.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/Funciones_TPI.cpp -o CMakeFiles/analisisHabitacional.dir/Funciones_TPI.s

CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.o: ../test/esEncuestaValidaTEST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/esEncuestaValidaTEST.cpp

CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/esEncuestaValidaTEST.cpp > CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.i

CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/esEncuestaValidaTEST.cpp -o CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.s

CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.o: ../test/histHabitacionalTEST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/histHabitacionalTEST.cpp

CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/histHabitacionalTEST.cpp > CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.i

CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/histHabitacionalTEST.cpp -o CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.s

CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.o: ../test/laCasaEstaQuedandoChicaTEST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/laCasaEstaQuedandoChicaTEST.cpp

CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/laCasaEstaQuedandoChicaTEST.cpp > CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.i

CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/laCasaEstaQuedandoChicaTEST.cpp -o CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.s

CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.o: ../test/creceElTeleworkingEnCiudadesGrandesTEST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/creceElTeleworkingEnCiudadesGrandesTEST.cpp

CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/creceElTeleworkingEnCiudadesGrandesTEST.cpp > CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.i

CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/creceElTeleworkingEnCiudadesGrandesTEST.cpp -o CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.s

CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.o: ../test/ordenarRegionYCODUSUTEST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/ordenarRegionYCODUSUTEST.cpp

CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/ordenarRegionYCODUSUTEST.cpp > CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.i

CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/ordenarRegionYCODUSUTEST.cpp -o CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.s

CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.o: ../test/muestraHomogeneaTEST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/muestraHomogeneaTEST.cpp

CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/muestraHomogeneaTEST.cpp > CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.i

CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/muestraHomogeneaTEST.cpp -o CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.s

CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.o: ../test/corregirRegionTEST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/corregirRegionTEST.cpp

CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/corregirRegionTEST.cpp > CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.i

CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/corregirRegionTEST.cpp -o CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.s

CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.o: CMakeFiles/analisisHabitacional.dir/flags.make
CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.o: ../test/indiceGiniTEST.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.o -c /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/indiceGiniTEST.cpp

CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/indiceGiniTEST.cpp > CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.i

CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/test/indiceGiniTEST.cpp -o CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.s

# Object files for target analisisHabitacional
analisisHabitacional_OBJECTS = \
"CMakeFiles/analisisHabitacional.dir/main.o" \
"CMakeFiles/analisisHabitacional.dir/auxiliares.o" \
"CMakeFiles/analisisHabitacional.dir/ejercicios.o" \
"CMakeFiles/analisisHabitacional.dir/Funciones_TPI.o" \
"CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.o" \
"CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.o" \
"CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.o" \
"CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.o" \
"CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.o" \
"CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.o" \
"CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.o" \
"CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.o"

# External object files for target analisisHabitacional
analisisHabitacional_EXTERNAL_OBJECTS =

../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/main.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/auxiliares.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/ejercicios.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/Funciones_TPI.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/test/esEncuestaValidaTEST.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/test/histHabitacionalTEST.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/test/laCasaEstaQuedandoChicaTEST.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/test/creceElTeleworkingEnCiudadesGrandesTEST.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/test/ordenarRegionYCODUSUTEST.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/test/muestraHomogeneaTEST.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/test/corregirRegionTEST.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/test/indiceGiniTEST.o
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/build.make
../analisisHabitacional: lib/googletest-master/googlemock/gtest/libgtestd.a
../analisisHabitacional: lib/googletest-master/googlemock/gtest/libgtest_maind.a
../analisisHabitacional: lib/googletest-master/googlemock/gtest/libgtestd.a
../analisisHabitacional: CMakeFiles/analisisHabitacional.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ../analisisHabitacional"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/analisisHabitacional.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/analisisHabitacional.dir/build: ../analisisHabitacional

.PHONY : CMakeFiles/analisisHabitacional.dir/build

CMakeFiles/analisisHabitacional.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/analisisHabitacional.dir/cmake_clean.cmake
.PHONY : CMakeFiles/analisisHabitacional.dir/clean

CMakeFiles/analisisHabitacional.dir/depend:
	cd /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug /home/daredevil/Documents/UNIV/ALGO1/TPI/TPI-Algoritmos1/src/cmake-build-debug/CMakeFiles/analisisHabitacional.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/analisisHabitacional.dir/depend
