### CTest reusing Boost tests from boost_demo
add_test(NAME ctest1_with_boost_tests COMMAND boost_demo)

### CTest with Catch tests inside + different flags
add_test(NAME ctest2-1_with_catch_tests COMMAND $<TARGET_FILE:test_runner>)
add_test(NAME ctest2-2_with_catch_tests_list_tags COMMAND $<TARGET_FILE:test_runner> --list-tags)
add_test(NAME ctest2-3_with_catch_tests_list_tests_verbosity COMMAND $<TARGET_FILE:test_runner> --list-tests --verbosity high)