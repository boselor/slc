cmake_minimum_required(VERSION 3.0)

# 括号里面填你的工程名
PROJECT(SLC_Compression)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

if (USE_SL)
    MESSAGE(STATUS "SLCSL is Enabled")
    SET(SLC_G Compression.cpp 7z/SevenZCompression.cpp)
else()
    MESSAGE(STATUS "SLCSL is Disabled")
    ADD_LIBRARY(slc_compression Compression.cpp 7z/SevenZCompression.cpp)
endif(USE_SL)