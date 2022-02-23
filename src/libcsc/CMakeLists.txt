cmake_minimum_required(VERSION 3.20)

project(libcsc)

add_library(my_time STATIC
        libcsc/time/MyTime.cpp
        libcsc/time/MyTime.h
        libcsc/time/TimeSpan.cpp
        libcsc/time/TimeSpan.h
        )

add_library(my_smartptr STATIC
        libcsc/smartptr/SharedPtr.cpp
        libcsc/smartptr/SharedPtr.h
        libcsc/smartptr/UniquePtr.cpp
        libcsc/smartptr/UniquePtr.h
        )

