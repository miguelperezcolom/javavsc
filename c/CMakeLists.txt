cmake_minimum_required(VERSION 3.6)
project(c)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(c ${SOURCE_FILES})