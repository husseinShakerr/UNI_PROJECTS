cmake_minimum_required(VERSION 3.29)
project(LAB5)

set(CMAKE_CXX_STANDARD 26)

add_executable(LAB5 main.cpp
        car.cpp
        car.h
        myPrint.cpp
        myPrint.h
        getGreaterSpeed.cpp
        getGreaterSpeed.h
        myBinOp.cpp
        myBinOp.h
        myUnOp.cpp
        myUnOp.h
        myFunc.cpp
        myFunc.h)
