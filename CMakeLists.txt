cmake_minimum_required(VERSION 3.10)
project(Enigma C)

set(CMAKE_C_STANDARD 11)


include_directories(bin, include)

add_executable(Enigma
        src/main.c
        src/core.c
        src/globals.c
        src/export.c
        src/imports.c
        src/utils.c
)