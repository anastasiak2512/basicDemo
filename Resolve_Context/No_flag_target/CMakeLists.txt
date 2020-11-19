set(SOURCE_FILES ../resolve_context.cpp)
add_library(resolve_context_no_flag ${SOURCE_FILES})

target_compile_definitions(resolve_context_no_flag PUBLIC -DSpecialFlag=0)
target_compile_definitions(resolve_context_no_flag PUBLIC -DMYNAMESPACE=TEST2)
