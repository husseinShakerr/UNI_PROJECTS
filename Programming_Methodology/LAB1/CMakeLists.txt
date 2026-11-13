cmake_minimum_required(VERSION 3.28)
project(LAB1)

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB1 main.cpp
        int_buffer.cpp
        int_buffer.h
        int_sorted.cpp
        int_sorted.h)
