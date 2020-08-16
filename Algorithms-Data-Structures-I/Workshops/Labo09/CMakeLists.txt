cmake_minimum_required(VERSION 3.6)
project(Labo09)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


set(SOURCE_FILES
        main.cpp
        ejercicios.cpp
		tests/indicePicoTEST.cpp
		tests/encontrarRotadoTEST.cpp
		tests/masCercanoKTEST.cpp
		tests/puntoFijoTEST.cpp
		tests/menorMasGrandeTEST.cpp
        tests/buscarTEST.cpp)

add_executable(Labo09 ${SOURCE_FILES})

target_link_libraries(Labo09 gtest gtest_main)
