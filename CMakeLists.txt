cmake_minimum_required(VERSION 3.6)
project(filetest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Class/main.cpp)
add_executable(filetest ${SOURCE_FILES})