#- Check CMake Install
#- Check CMake completion
#- Check file references (Rename)
#- Check live templates (boost, boost with libs)

add_executable(CMake_support main.cpp Boo.h)

function(printtwice varValue varName)
    set(${varName} ${varValue}${varValue} PARENT_SCOPE)
endfunction(printtwice)

set(arg foo)
printtwice(${arg} arg)
message("arg = " ${arg})

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/Install CACHE PATH "install here" FORCE)

install(TARGETS CMake_support DESTINATION deb CONFIGURATIONS Debug)
install(TARGETS CMake_support DESTINATION rel CONFIGURATIONS Release)
install(CODE "execute_process(COMMAND my_script.sh)")
install(FILES Boo.h DESTINATION src)