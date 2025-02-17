cmake_minimum_required(VERSION 3.27)
project(lab_1_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_1_cpp main.cpp
        SortingBenchmark.cpp
        SortingBenchmark.h
        SortingAlgorithms.cpp
        SortingAlgorithms.h
        ArrayGenerator.cpp
        ArrayGenerator.h
        Helpers.cpp
        Helpers.h)
