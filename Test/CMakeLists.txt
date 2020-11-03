cmake_minimum_required (VERSION 3.14)
project(NonUITest)

include_directories(../3rdparty/catch2_single_include)
add_executable(${PROJECT_NAME} main.cpp)
