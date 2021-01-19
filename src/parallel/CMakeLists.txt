# 括号里面填你的工程名
PROJECT(SLCParallel)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

MESSAGE(STATUS "Begin to build slc_parallel")
if (USE_SL)
    SET(SLC_G ParallelMath.cpp)
else()
    SET(SLC_L ParallelMath.cpp)
    ADD_LIBRARY(slc_parallel ${SLC_L})
    TARGET_LINK_LIBRARIES(slc_parallel slc_core slc_logger slc_io)
endif(USE_SL)