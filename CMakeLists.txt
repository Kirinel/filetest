cmake_minimum_required(VERSION 3.6)
project(filetest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Class/main.cpp Class/FileTool/FileTool.cpp Class/FileTool/FileTool.h Class/RegexTool/RegexTool.cpp Class/RegexTool/RegexTool.h Class/WebTool/WebTool.cpp Class/WebTool/WebTool.h)
add_executable(filetest ${SOURCE_FILES})