set(SOURCE_FILES color_point.cpp)

add_library(pch ${SOURCE_FILES})
target_precompile_headers(pch
        PUBLIC
            ../point_lib/Point.h)
