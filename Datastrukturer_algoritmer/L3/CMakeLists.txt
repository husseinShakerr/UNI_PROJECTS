cmake_minimum_required(VERSION 3.31)
project(L3)

set(CMAKE_CXX_STANDARD 26)

add_executable(L3 main.cpp
        generator.cpp
        generator.h
        search.cpp
        search.h
        bst.cpp
        bst.h
        timer.cpp
        timer.h
        reporter.cpp
        reporter.h
        tester.cpp
        tester.h
        hashTable.cpp
        hashTable.h)
