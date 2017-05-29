cmake_minimum_required(VERSION 3.4)
project(demoMore)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp 2_MacroCompletion.cpp 1_SmartCompletion.cpp 7_ChangeSignature.cpp 5_DFAchecks.cpp 4_GoToFail.cpp 3_InferType.cpp 8_DoxygenSample.h 6_ExtractSmth.cpp 6_ExtractSmth.h Distance.cpp Distance.h 5_0_CodeAnalysis.cpp)
add_executable(demoMore ${SOURCE_FILES})