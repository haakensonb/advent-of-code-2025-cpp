cmake_minimum_required(VERSION 4.0)
project(advent_of_code_2025_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(advent_of_code_2025_cpp main.cpp
        day/day_1/dial.h
        common/common.h)
