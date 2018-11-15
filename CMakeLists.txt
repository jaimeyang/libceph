cmake_minimum_required(VERSION 3.12)
project(rados)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/include)

add_executable(rados main.cpp)