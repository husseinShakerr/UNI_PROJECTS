cmake_minimum_required(VERSION 3.28)
project(Labyrinth)

set(CMAKE_CXX_STANDARD 23)

add_executable(Labyrinth main.cpp
        labyrinth.h
        labyrinth.cpp)
