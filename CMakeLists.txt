cmake_minimum_required(VERSION 3.20)
project(5d C)

set(CMAKE_C_STANDARD 11)

add_executable(5d main.c)
add_subdirectory(libs)
