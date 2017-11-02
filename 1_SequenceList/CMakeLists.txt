cmake_minimum_required(VERSION 3.8)
project(1_SequenceList)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c SequenceList.h SequenceList.c)
add_executable(1_SequenceList ${SOURCE_FILES})