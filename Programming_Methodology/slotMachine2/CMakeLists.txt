cmake_minimum_required(VERSION 3.29)
project(slotMachine2)

set(CMAKE_CXX_STANDARD 26)

add_executable(slotMachine2 main.cpp
        graphics.cpp
        graphics.h
        menu.cpp
        menu.h
        button.cpp
        button.h
        menuCreator.cpp
        menuCreator.h
        slotMachine.cpp
        slotMachine.h
        engine.cpp
        engine.h
)

include_directories(include)

target_link_directories(slotMachine2 PUBLIC lib)

target_link_libraries(slotMachine2 sfml-graphics sfml-window sfml-system opengl32)