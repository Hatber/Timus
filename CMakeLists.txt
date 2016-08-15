cmake_minimum_required(VERSION 3.3)
project(Timus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES Task/*.cpp)

add_executable(Timus main.cpp ${SOURCE_FILES})