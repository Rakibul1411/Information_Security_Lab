cmake_minimum_required(VERSION 3.28)
project(sha512_smdi_)

set(CMAKE_CXX_STANDARD 17)

add_executable(sha512_smdi_ main.cpp
        sha512.h)
