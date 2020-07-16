# tried to exclude all unsupported toolchains, need also exclude WSL and probably add Linux + clang back
if ((UNIX AND "${CMAKE_CXX_COMPILER_ID}" NOT MATCHES "GNU")
        OR (WIN32 AND NOT MSVC)
        OR CYGWIN)
    message(STATUS "No CUDA support")
    return()
endif()

find_package(CUDA)

if (CUDA_FOUND)
    enable_language(CUDA)
    set(CMAKE_CUDA_STANDARD 14)

    add_executable(cuda_exec cuda_sample.cu)
endif ()
