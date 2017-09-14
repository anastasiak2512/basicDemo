set(SOURCE_FILES color_point.cpp)

add_library(pch ${SOURCE_FILES})
set_source_files_properties(color_point.cpp PROPERTIES
        COMPILE_FLAGS "-include ../../point_lib/Point.h")
