cmake_minimum_required(VERSION 3.8)
project(C_Project)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c 04_SinglyLinkedList.h 04_SinglyLinkedList.c)
add_executable(C_Project ${SOURCE_FILES})