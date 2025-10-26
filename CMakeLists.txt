cmake_minimum_required(VERSION 3.10)
project(Enigma C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(Enigma
        src/main.c
        src/barrels.c
        src/functions.c
)