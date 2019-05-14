add_definitions(-DSpecialFlag=0)
add_definitions(-DMYNAMESPACE=test2)
set(SOURCE_FILES ../resolve_context.cpp)
add_library(resolve_context_no_flag ${SOURCE_FILES})