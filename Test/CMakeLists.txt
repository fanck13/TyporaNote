cmake_minimum_required (VERSION 3.14)
project(NonUITest)

include_directories(../3rdparty/catch2_single_include)

FILE(GLOB SRC_FILES "./*.cpp") 

add_executable(${PROJECT_NAME} ${SRC_FILES})

