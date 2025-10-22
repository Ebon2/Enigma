cmake_minimum_required(VERSION 3.10)
project(Enigma C)

set(CMAKE_C_STANDARD 11)

include_directories(constans)
add_executable(Enigma
        main.c
        constans/barrels.c
        constans/functions.c
)