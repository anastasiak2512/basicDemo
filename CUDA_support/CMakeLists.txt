# tried to exclude all unsupported toolchains, need also exclude WSL and probably add Linux + clang back
if (APPLE OR (WIN32 AND NOT MSVC) OR CYGWIN)
    return()
endif()

enable_language(CUDA)
set(CMAKE_CUDA_STANDARD 14)

add_executable(cuda_exec cuda_sample.cu)