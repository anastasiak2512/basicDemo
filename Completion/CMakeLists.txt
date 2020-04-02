set(SOURCE_FILES SmartCompletion.cpp
        MacroCompletion.cpp)

add_library(code_completion ${SOURCE_FILES})

add_executable(code_completion_concepts concepts.cpp)
set_target_properties(code_completion_concepts PROPERTIES CXX_STANDARD 20)