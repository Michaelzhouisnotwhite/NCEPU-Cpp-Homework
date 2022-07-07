cmake_minimum_required(VERSION 3.17)
project(test02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(test03
        src/header.h
        src/main.cpp src/MiniSize.cpp)
