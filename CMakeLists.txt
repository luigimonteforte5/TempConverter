cmake_minimum_required(VERSION 3.30)
project(TempConverter)

set(CMAKE_CXX_STANDARD 20)

add_executable(TempConverter main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
