cmake_minimum_required(VERSION 3.3)
project(Networking3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread ")

set(SOURCE_FILES
        PracticalSocket.cpp
        PracticalSocket.h
        simplehttpserver.cpp RequestHandler.cpp RequestHandler.hpp HTTPHandler.cpp HTTPHandler.h HTTP_Headers.hpp)

add_executable(Networking3 ${SOURCE_FILES})