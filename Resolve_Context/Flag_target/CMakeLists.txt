set(SOURCE_FILES ../resolve_context.cpp)
add_library(resolve_context_flag ${SOURCE_FILES})

target_compile_definitions(resolve_context_flag PUBLIC -DSpecialFlag=1)
target_compile_definitions(resolve_context_flag PUBLIC -DMYNAMESPACE=TEST)
