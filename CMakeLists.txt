cmake_minimum_required(VERSION 3.3)
project(Timus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES Task/*.cpp)

add_executable(Timus main.cpp ${SOURCE_FILES})

#CMAKE_SOURCE_DIR
add_definitions(-D_SOURCE_PATH_=${CMAKE_SOURCE_DIR})
project(ProjectBuilder)
add_executable(ProjectBuilder SingleFileBuilder.cpp)
