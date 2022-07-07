cmake_minimum_required(VERSION 3.17)
project(test01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(test01
        EqCorpusInterest.cpp
        EqCorpusInterest.h
        header.h
        Loan.cpp
        Loan.h
        main.cpp
        EqCorpus.h
        EqCorpus.cpp)
