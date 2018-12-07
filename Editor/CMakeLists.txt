if($ENV{CLION_IDE})
    message("CLion IDE is running!")
elseif()
    message("Non-CLion is running!")
endif()

set(SOURCE_FILES Operator_usages_highlight.cpp
        breadcrumbs.cpp control_statements_folding.cpp
        unwrap.cpp ide_macro.cpp)

add_library(editor_lib ${SOURCE_FILES})
