#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE module1
#include <boost/test/included/unit_test.hpp>

#define MY_ONE 1

BOOST_AUTO_TEST_SUITE(demo_suite)

    BOOST_AUTO_TEST_CASE(test_one)
    {
        BOOST_CHECK_EQUAL(MY_ONE, 1);
    }

    //Debug test with Valgrind Memcheck
    BOOST_AUTO_TEST_CASE(test_two)
    {
        char *name = new char[4];
        name[1] = 't';
        name[2] = 'e';
        name[3] = 's';
        name[4] = 't';

        BOOST_CHECK_EQUAL(name, "test");
    }

BOOST_AUTO_TEST_SUITE_END()