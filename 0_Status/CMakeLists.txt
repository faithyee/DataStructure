cmake_minimum_required(VERSION 3.8)
project(0_Status)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Status.h)
add_executable(0_Status ${SOURCE_FILES})