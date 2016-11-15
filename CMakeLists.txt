cmake_minimum_required(VERSION 3.6)
project(demoMore)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DemoSamples.cpp DemoSamples.h MacroCompletion.cpp MacroCompletion.h SmartCompletion.cpp SmartCompletion.h ChangeSignature.cpp ChangeSignature.h DFAchecks.cpp DFAchecks.h GoToFail.cpp GoToFail.h InferType.cpp InferType.h DoxygenSample.cpp DoxygenSample.h ExtractSmth.cpp ExtractSmth.h Distance.cpp Distance.h)
add_executable(demoMore ${SOURCE_FILES})