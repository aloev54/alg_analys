cmake_minimum_required(VERSION 3.27)
project(lab_2_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_2_cpp main.cpp
        StrGenerator.cpp
        StrGenerator.h
        LevenshteinAlgorithms.cpp
        LevenshteinAlgorithms.h
        LevenshteinBenchmark.cpp
        LevenshteinBenchmark.h)
