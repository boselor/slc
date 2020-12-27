cmake_minimum_required(VERSION 3.0)

# 括号里面填你的工程名
PROJECT(SLC_Configuration)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

if (USE_SL)
    MESSAGE(STATUS "SLCSL is Enabled")
    SET(SLC_G IniConfigure.cpp)
else()
    MESSAGE(STATUS "SLCSL is Disabled")
    ADD_LIBRARY(slc_configure IniConfigure.cpp)
endif(USE_SL)