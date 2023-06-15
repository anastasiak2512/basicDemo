
set(CMAKE_CXX_STANDARD 17)

configure_file(CMakeLists.txt.in catch2test-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/catch2test-download )
if(result)
    message(FATAL_ERROR "CMake step for catch2test failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/catch2test-download )
if(result)
    message(FATAL_ERROR "Build step for catch2test failed: ${result}")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/catch2test-src
        ${CMAKE_CURRENT_BINARY_DIR}/catch2test-build
        EXCLUDE_FROM_ALL)

include_directories("${Catch2_SOURCE_DIR}/include")
add_executable(catch3_test_project_sample test_failed.cpp test_passed.cpp test_skipped.cpp)
target_link_libraries(catch3_test_project_sample PRIVATE Catch2::Catch2WithMain)
