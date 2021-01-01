# 括号里面填你的工程名
PROJECT(SLCDAO)

INCLUDE_DIRECTORIES(${SLC_INCLUDE})

if (USE_SL)
    MESSAGE(STATUS "SLCSL is Enabled")
    SET(SLC_G SQLAdapter.cpp SQLReader.cpp sqlite3/sqlite3.c sqlite3/shell.c)
else()
    MESSAGE(STATUS "SLCSL is Disabled")
    SET(SLC_L SQLAdapter.cpp SQLReader.cpp sqlite3/sqlite3.c sqlite3/shell.c)
    ADD_LIBRARY(slc_dao ${SLC_L})
    TARGET_LINK_LIBRARIES(slc_dao slc_core slc_sqlite)
endif(USE_SL)