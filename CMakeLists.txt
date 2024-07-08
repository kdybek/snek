cmake_minimum_required(VERSION 3.28)
project(snek)

set(CMAKE_CXX_STANDARD 20)

add_executable(snek
        src/main.cpp
        src/map.cpp
        src/map.h
        src/snek.h
        src/utility.h
        src/windows_console_screen_buffer.h
        src/snek_except.h
        src/constants.h
        src/constants.h)
