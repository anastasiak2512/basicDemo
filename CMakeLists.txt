cmake_minimum_required(VERSION 3.17)
project(demoMore)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES main.cpp)
add_executable(demoMore ${SOURCE_FILES})

add_subdirectory(Code_Analysis)

add_subdirectory(Code_Generation)
add_subdirectory(Completion)
add_subdirectory(Documentation)
add_subdirectory(Param_Info)
add_subdirectory(Refactoring)

add_subdirectory(Catch_tests)
add_subdirectory(Boost_tests)
add_subdirectory(Doctest_tests)

add_subdirectory(precompiled_header)
add_subdirectory(Navigation)
add_subdirectory(Editor)
add_subdirectory(StartNewDemo)
add_subdirectory(Resolve_Context)

add_subdirectory(CMake_support)
add_subdirectory(CUDA_support)

add_subdirectory(Debug_demo)
add_subdirectory(Debug_extra)

add_subdirectory(Valgrind_memcheck)
add_subdirectory(Sanitizers)
add_subdirectory(Coverage)
add_subdirectory(Profiler)

add_subdirectory(Remote_Dev)