cmake_minimum_required(VERSION 3.28)
project(AES_ECB)

set(CMAKE_CXX_STANDARD 17)

add_executable(AES_ECB main.cpp
        aesECB.h)
