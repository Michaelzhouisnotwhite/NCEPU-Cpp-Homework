
cmake_minimum_required(VERSION 3.17)
project(test02)

set(CMAKE_CXX_STANDARD 14)

#include_directories(src)
#set_directory_properties(src)
add_executable(test02 src/main.cpp src/TwoDimensionTensor.cpp )
