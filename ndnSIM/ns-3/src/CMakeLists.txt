cmake_minimum_required(VERSION 3.6)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ndnSIM/NFD/daemon/table/nl.cpp ndnSIM/NFD/daemon/table/nl.h)
add_executable(src ${SOURCE_FILES})