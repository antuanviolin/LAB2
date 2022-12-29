cmake_minimum_required(VERSION 3.21)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest-main)
include_directories(googletest-main/googletest/include)
add_executable(Lab2 main.cpp Life.cpp Life.h interface.cpp interface.h test.cpp)
target_link_libraries(Lab2 gtest gtest_main)