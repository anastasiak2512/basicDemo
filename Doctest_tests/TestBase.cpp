// FILE_TESTS_FILE

#include "doctest.h"
#include <iostream>

// helper for throwing exceptions
template<typename T>
int throw_if(bool in, const T &ex) {
  if (in)
#ifndef DOCTEST_CONFIG_NO_EXCEPTIONS
    throw ex;
#else // DOCTEST_CONFIG_NO_EXCEPTIONS
    ((void) ex);
#endif// DOCTEST_CONFIG_NO_EXCEPTIONS
  return 42;
}

const char *SMALL_BAD_XML =
    "<xml><root> &<> captured &amp; &gt; &lt; section</root></xml>";

// { ========================== logging

DOCTEST_MAKE_STD_HEADERS_CLEAN_FROM_WARNINGS_ON_WALL_BEGIN
#include <vector>
DOCTEST_MAKE_STD_HEADERS_CLEAN_FROM_WARNINGS_ON_WALL_END

TEST_CASE("logging the counter of a loop") {
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(4);
  vec.push_back(8);
  vec.push_back(16);

  std::cout << "to std::cout" << std::endl;
  std::cerr << "to std::err" << std::endl;

  INFO("current iteration of loop:");
  for (unsigned i = 0; i < vec.size(); ++i) {
    CAPTURE(i);
    CHECK(vec[i] != (1 << i));
  }
}

static int someTests() {
  int some_var = 42;
  INFO("lots of captures - some on heap: " << some_var << " " << some_var << " "
                                           << some_var << ";");
  FAIL_CHECK("forcing the many captures (including those on the heap) to be "
             "stringified");
  return some_var;
}

TEST_CASE("a test case that will end from an exception") {
  int some_var = someTests();
  INFO("someTests() returned: "
       << some_var);// note that we have to use a local variable - cannot pass
  // a temporary
  INFO("this should be printed if an exception is thrown even if no assert has "
       "failed: "
       << some_var);
  {
    INFO("in a nested scope this should be printed as well: " << some_var);
    {
      INFO("this should not be printed");
      CAPTURE(some_var);
    }

    CHECK_MESSAGE(some_var == 666, "why is this not 666 ?!");

    throw_if(true, 0);
  }
}

TEST_CASE("a test case that will end from an exception and should print the "
          "unprinted context") {
  INFO("should be printed even if an exception is thrown and no assert fails "
       "before that");
  throw_if(true, 0);
}

static void thirdPartyAssert(bool result, bool is_fatal, const char *file,
                             int line) {
  if (!result) {
    if (is_fatal)
      ADD_FAIL_AT(file, line, "MY_ASSERT_FATAL(" << result << ")");
    else
      ADD_FAIL_CHECK_AT(file, line, "MY_ASSERT(" << result << ")");
  }
}

#define MY_ASSERT(x) thirdPartyAssert(x, false, __FILE__, __LINE__)
#define MY_ASSERT_FATAL(x) thirdPartyAssert(x, true, __FILE__, __LINE__)

TEST_CASE("third party asserts can report failures to doctest") {
  MY_ASSERT(1 == 2);
  MY_ASSERT_FATAL(1 == 2);
}

TEST_CASE("explicit failures 1") {
  FAIL_CHECK("this should not end the test case, but mark it as failing");
  MESSAGE("reached!");
}

TEST_CASE("explicit failures 2") {
  FAIL("fail the test case and also end it");
  MESSAGE("never reached...");
}

// } ========================== logging

// { ========================== structure
TEST_CASE("foo") {}// not part of any test suite

TEST_SUITE_BEGIN("utils");
TEST_CASE("00") {
  SUBCASE("1") {
    SUBCASE("1.1") {
      CHECK(false);
      SUBCASE("1.1.1") {}
    }
    SUBCASE("1.2") {}
  }
  SUBCASE("2") {}
}// part of the utils test suite
TEST_CASE("11") {}
TEST_SUITE_END();
// } ========================== structure

// { ========================== decorators
TEST_CASE("name" * doctest::description("shouldn't take more than 500ms") *
          doctest::timeout(0.5)) {
  // asserts
}

TEST_SUITE("some TS" * doctest::description("all tests will have this")) {
  TEST_CASE("has a description from the surrounding test suite") {
    // asserts
  }
}
TEST_SUITE("some TS") {
  TEST_CASE(
      "no description even though in the same test suite as the one above") {
    // asserts
  }
}
// } ========================== decorators
