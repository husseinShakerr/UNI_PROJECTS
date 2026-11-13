cmake_minimum_required(VERSION 3.29)
project(LAB2)

set(CMAKE_CXX_STANDARD 26)

add_executable(LAB2 main.cpp
        shape.cpp
        shape.h
        circle.cpp
        circle.h
        rectangle.cpp
        rectangle.h
        cylinder.cpp
        cylinder.h
        parallelepiped.cpp
        parallelepiped.h
        rounded_rectangle.cpp
        rounded_rectangle.h
        square.cpp
        square.h)
