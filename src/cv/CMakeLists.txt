cmake_minimum_required(VERSION 3.0)

# 括号里面填你的工程名
PROJECT(SLCCV)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

if (USE_SL)
    MESSAGE(STATUS "SLCSL is Enabled")
    SET(SLC_G videos/VideoCapture.cpp)
else()
    MESSAGE(STATUS "SLCSL is Disabled")
    SET(SLC_L videos/VideoCapture.cpp)
    ADD_LIBRARY(slc_cv ${SLC_L})
    TARGET_LINK_LIBRARIES(slc_cv slc_core slc_logger)
endif(USE_SL)