# 括号里面填你的工程名
PROJECT(SLCCV)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

set(OpenCV_DIR D:/Env/opencv/mingw/)

FIND_PACKAGE(OpenCV REQUIRED)

if (USE_SL)
    MESSAGE(STATUS "SLCSL is Enabled")
    SET(SLC_G common/MatrixOperator.cpp videos/VideoCapture.cpp)
else()
    MESSAGE(STATUS "SLCSL is Disabled")
    SET(SLC_L common/MatrixOperator.cpp videos/VideoCapture.cpp)
    ADD_LIBRARY(slc_cv ${SLC_L})
    TARGET_LINK_LIBRARIES(slc_cv slc_core slc_logger ${OpenCV_LIBS})
endif(USE_SL)