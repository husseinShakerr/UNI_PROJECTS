cmake_minimum_required(VERSION 3.31)
project(L2)

set(CMAKE_CXX_STANDARD 26)

add_executable(L2 main.cpp
        generator.cpp
        generator.h
        sorter.cpp
        sorter.h
        timer.cpp
        timer.h
        report.cpp
        report.h
        tester.cpp
        tester.h)
