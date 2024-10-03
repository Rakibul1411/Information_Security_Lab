cmake_minimum_required(VERSION 3.27)
project(AES_Rakin C)

set(CMAKE_C_STANDARD 11)

add_executable(AES_Rakin main.c
        runner.c
        variable.c
        header.h)
