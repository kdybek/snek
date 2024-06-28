cmake_minimum_required(VERSION 3.28)
project(snek)

set(CMAKE_CXX_STANDARD 20)

add_executable(snek
        src/Main.cpp
        src/Map.cpp
        src/Map.h
        src/Snek.h
        src/Utility.h
        src/WindowsConsoleScreenBuffer.h
        src/SnekExcept.h
        src/Constants.h
        src/Constants.h)
