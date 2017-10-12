cmake_minimum_required(VERSION 3.8)
project(demoMore)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(demoMore ${SOURCE_FILES})

add_subdirectory(Code_Analysis)
add_subdirectory(Code_Generation)
add_subdirectory(Completion)
add_subdirectory(Documentation)
add_subdirectory(Refactoring)
add_subdirectory(Catch_tests)
add_subdirectory(precompiled_header)
add_subdirectory(Navigation)