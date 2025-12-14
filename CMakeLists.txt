cmake_minimum_required(VERSION 3.10)
project(advent_of_code_2025_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR})

add_compile_definitions(PROJECT_ROOT="${PROJECT_SOURCE_DIR}")

add_executable(advent_of_code_2025_cpp main.cpp)

# Google Test setup
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP ON
)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(day_1_test test/day_1_test.cpp)
target_link_libraries(day_1_test GTest::gtest_main)
add_test(NAME Day1Tests COMMAND day_1_test)