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

SET(SLC_G src/slc.cpp)

ADD_SUBDIRECTORY(src/core)
ADD_SUBDIRECTORY(src/compression)
ADD_SUBDIRECTORY(src/log)

ADD_LIBRARY(slc ${SLC_G})
ADD_EXECUTABLE(slce src/slc.cpp)
TARGET_LINK_LIBRARIES(slce slc_logger)