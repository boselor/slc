cmake_minimum_required(VERSION 3.0)

# 括号里面填你的工程名
PROJECT(SLCTOOLS)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

if (USE_SL)
    MESSAGE(STATUS "SLCSL is Enabled")
    SET(SLC_G Logger.cpp)
else()
    MESSAGE(STATUS "SLCSL is Disabled")
    SET(SLC_L Logger.cpp)
    ADD_LIBRARY(slc_logger ${SLC_L})
    TARGET_LINK_LIBRARIES(slc_logger slc_core)
endif(USE_SL)