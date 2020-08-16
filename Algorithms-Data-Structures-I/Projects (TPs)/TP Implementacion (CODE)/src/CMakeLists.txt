cmake_minimum_required(VERSION 3.6)
project(analisisHabitacional)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES main.cpp
        auxiliares.cpp
        ejercicios.cpp
        Funciones_TPI.cpp
        test/esEncuestaValidaTEST.cpp
        test/histHabitacionalTEST.cpp
        test/laCasaEstaQuedandoChicaTEST.cpp
        test/creceElTeleworkingEnCiudadesGrandesTEST.cpp
        test/ordenarRegionYCODUSUTEST.cpp
        test/muestraHomogeneaTEST.cpp
        test/corregirRegionTEST.cpp
        test/indiceGiniTEST.cpp)

add_executable(analisisHabitacional ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "-g --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(analisisHabitacional gtest gtest_main)
