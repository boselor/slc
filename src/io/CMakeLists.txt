# 括号里面填你的工程名
PROJECT(SLCIO)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

if (USE_SL)
    MESSAGE(STATUS "SLCSL is Enabled")
    SET(SLC_G File.cpp)
else()
    MESSAGE(STATUS "SLCSL is Disabled")
    SET(SLC_L File.cpp)
    ADD_LIBRARY(slc_io ${SLC_L})
    TARGET_LINK_LIBRARIES(slc_io slc_core slc_logger)
endif(USE_SL)