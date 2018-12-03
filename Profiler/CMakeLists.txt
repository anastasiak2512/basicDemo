set(CMAKE_CXX_FLAGS "-fno-omit-frame-pointer -O0")

add_executable(thread_app thread_app.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(thread_app Threads::Threads)