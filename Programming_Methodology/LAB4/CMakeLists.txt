cmake_minimum_required(VERSION 3.29)
project(LAB4)

set(CMAKE_CXX_STANDARD 26)

add_executable(LAB4 main.cpp
        email.cpp
        email.h
        mailbox.cpp
        mailbox.h)
