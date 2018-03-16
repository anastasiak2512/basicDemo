#Don't forget to add -DCMAKE_MODULE_PATH=<qt5 path>

find_package(Qt5Widgets REQUIRED)

add_library(arkanoidLib Ball.cpp Ball.h GameObject.cpp GameObject.h Brick.cpp Brick.h Collisions.cpp Collisions.h GameState.cpp GameState.h)
target_link_libraries(arkanoidLib Qt5::Widgets)

set(SOURCE_FILES main.cpp GameWidget.cpp GameWidget.h)
add_executable(arkanoid ${SOURCE_FILES})
target_link_libraries(arkanoid arkanoidLib)

macro(copy_dll target comp)
    add_custom_command(
            TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Qt5::${comp}>
            $<TARGET_FILE_DIR:${target}>
    )
endmacro()

if (WIN32)
    copy_dll(arkanoid Core)
    copy_dll(arkanoid Gui)
    copy_dll(arkanoid Widgets)
    if (MINGW) # hacky way to make things work; proper way would be building Qt with correct MinGW
        add_custom_command(
                TARGET arkanoid POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE_DIR:Qt5::Widgets>/libstdc++-6.dll
                $<TARGET_FILE_DIR:arkanoid>
        )
    endif()
endif()

add_subdirectory(3rdparty/googletest)
add_executable(arkanoidTest test.cpp)
target_link_libraries(arkanoidTest gtest_main arkanoidLib)