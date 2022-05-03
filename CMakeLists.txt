cmake_minimum_required(VERSION 3.20)
project(ITMO_CPP_Projects)

set(CMAKE_CXX_STANDARD 14)

add_executable(ITMO_CPP_Projects "CircularBuffer/main.cpp" "CircularBuffer/CircularBuffer.h" "CircularBuffer/algorithms.h")
