# 括号里面填你的工程名
PROJECT(SLCAccelerator)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

MESSAGE(STATUS "Begin to build slc_accelerator")

option (USE_CUDA
        "Build with cuda" OFF)

if (USE_CUDA)
    ADD_SUBDIRECTORY(src/accelerate/cuda)
endif (USE_CUDA)