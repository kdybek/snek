cmake_minimum_required(VERSION 3.28)
project(snek)

set(CMAKE_CXX_STANDARD 20)

add_executable(snek
        src/main.cpp
        src/Map.cpp
        src/Map.h
        src/snek.h
        src/Utility.h
        src/WindowsConsoleScreenBuffer.h
        src/SnekExcept.h)
