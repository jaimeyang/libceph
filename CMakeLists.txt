cmake_minimum_required(VERSION 3.10)
project(ceph-client)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/include)

LINK_LIBRARIES(rados)

add_executable(ceph-client main.cpp ceph.cpp ceph.h)