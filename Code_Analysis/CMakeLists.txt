set(SOURCE_FILES
        CodeAnalysis.cpp
        DFAchecks.cpp
        Clang_Tidy_modernize.cpp
        Clang_Tidy_google.cpp
        Clang_Tidy_cppcoreguidelines.cpp
        cppcast_quickfixes.cpp
        GoToFail.cpp
        Clang_Tidy_options.cpp
        argument_selection_inspection.cpp
        code_analysis_summary.cpp
        naming_inspections.cpp
        )

add_library(code_analysis ${SOURCE_FILES})
