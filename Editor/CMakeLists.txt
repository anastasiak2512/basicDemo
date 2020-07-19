if($ENV{CLION_IDE})
    message("CLion IDE is running!")
elseif()
    message("Non-CLion is running!")
endif()

set(SOURCE_FILES operator_usages_highlight.cpp
        breadcrumbs.cpp control_statements_folding.cpp
        unwrap.cpp ide_macro.cpp injected_languages.cpp
        cpp20.cpp concepts.cpp)

add_library(editor_lib ${SOURCE_FILES})
