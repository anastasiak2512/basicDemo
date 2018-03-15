set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/Install CACHE PATH "install here" FORCE)

add_executable(CMake_support main.cpp Foo.h)

install(TARGETS CMake_support DESTINATION deb CONFIGURATIONS Debug)
install(TARGETS CMake_support DESTINATION rel CONFIGURATIONS Release)
install(FILES Foo.h DESTINATION src)