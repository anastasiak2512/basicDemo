add_definitions(-DSpecialFlag=1)
add_definitions(-DMYNAMESPACE=test)
set(SOURCE_FILES ../resolve_context.cpp)
add_library(resolve_context_flag ${SOURCE_FILES})