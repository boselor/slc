# 括号里面填你的工程名
PROJECT(SLCAlgorithm)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

MESSAGE(STATUS "Begin to build slc_parallel")
if (USE_SL)
    SET(SLC_G AdjacencyList.cpp)
else()
    SET(SLC_L AdjacencyList.cpp)
    ADD_LIBRARY(slc_algorithm ${SLC_L})
    TARGET_LINK_LIBRARIES(slc_algorithm slc_core slc_logger)
endif(USE_SL)