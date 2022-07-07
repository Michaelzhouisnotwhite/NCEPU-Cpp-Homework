cmake_minimum_required(VERSION 3.17)
project(test02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(test02
        src/header.h
        src/main.cpp src/ThreeDimensionTensor.cpp src/ThreeDimensionTensor.h)
