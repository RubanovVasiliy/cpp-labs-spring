cmake_minimum_required(VERSION 3.20)

project(libcsc)

add_library(my_time STATIC
        libcsc/time/MyTime.cpp
        libcsc/time/MyTime.h
        libcsc/time/TimeSpan.cpp
        libcsc/time/TimeSpan.h
        )

