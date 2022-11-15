set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/mod)

function(add_module name)
    file(MAKE_DIRECTORY ${PREBUILT_MODULE_PATH})
    add_custom_target(${name}.pcm
            COMMAND
            ${CMAKE_CXX_COMPILER}
            -std=gnu++20
            -x c++
            -fmodules
#            --target=x86_64-apple-macosx12.6.0
            -c
            ${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}
            -Xclang -emit-module-interface
            -o ${PREBUILT_MODULE_PATH}/${name}.pcm
            )
endfunction()


add_compile_options(-fmodules)
add_compile_options(-fbuiltin-module-map)
add_compile_options(-fimplicit-module-maps)
add_compile_options(-fprebuilt-module-path=${PREBUILT_MODULE_PATH})
add_compile_options(--target=x86_64-apple-macosx12.6.0)

add_module(AdvancedMath AdvancedMath.cppm)
add_module(Talk language.cppm)
add_executable(Modules
        main.cpp
        AdvancedMath.cppm
        language.cppm
        )
add_dependencies(Modules AdvancedMath.pcm Talk.pcm)

