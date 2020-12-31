# 括号里面填你的工程名
PROJECT(SLCDAO)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

# ADD_SUBDIRECTORY(sqlite)

if (USE_SL)
    MESSAGE(STATUS "SLCSL is Enabled")
    SET(SLC_G SQLAdapter.cpp SQLReader.cpp)
else()
    MESSAGE(STATUS "SLCSL is Disabled")
    SET(SLC_L SQLAdapter.cpp SQLReader.cpp sqlite/sqlite3.c)
    ADD_LIBRARY(slc_dao ${SLC_L})
    TARGET_LINK_LIBRARIES(slc_dao slc_core)
endif(USE_SL)