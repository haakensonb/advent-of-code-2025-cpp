cmake_minimum_required(VERSION 4.0)
project(advent_of_code_2025_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR})

add_compile_definitions(PROJECT_ROOT="${PROJECT_SOURCE_DIR}")

add_executable(advent_of_code_2025_cpp main.cpp)