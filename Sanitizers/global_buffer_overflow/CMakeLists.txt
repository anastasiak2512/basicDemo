cmake_minimum_required(VERSION 3.9)
project(global_buffer_overflow)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g")

add_executable(global_buffer_overflow global_buffer_overflow_case.cpp)