# 最低指定的CMake版本
cmake_minimum_required(VERSION 3.15)

# 括号里面填你的工程名
PROJECT(slc)
SET(PROJECT_DIR /)

# 头文件路径
SET(SLC_INCLUDE ${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${SLC_INCLUDE})
# 是否使用自己的 MathFunctions 库
option (USE_SL
       "Build SLC with a single lib" OFF)

SET(SLC_G sBrc/slc.cpp)

ADD_SUBDIRECTORY(src/core)

option (USE_CV
        "Build with opencv" ON)
if (USE_CV)
    ADD_SUBDIRECTORY(src/cv)
endif (USE_CV)

ADD_SUBDIRECTORY(src/accelerate)
#option (USE_GDAL
#        "Build with gdal" OFF)
#if (USE_CV)
#    ADD_SUBDIRECTORY(src/gdal)
#endif (USE_CV)

ADD_SUBDIRECTORY(src/compression)
ADD_SUBDIRECTORY(src/log)
# ADD_SUBDIRECTORY(src/dao)
ADD_SUBDIRECTORY(src/parallel)
ADD_SUBDIRECTORY(src/algorithm)
ADD_SUBDIRECTORY(src/io)

# ADD_LIBRARY(slc ${SLC_G})
ADD_EXECUTABLE(slce src/slc.cpp)
TARGET_LINK_LIBRARIES(slce slc_logger slc_core slc_cv slc_io)