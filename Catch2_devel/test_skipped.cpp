#include "catch2/catch_all.hpp"

TEST_CASE("skip_catch_test")
{
    SKIP();
    CHECK_FALSE(0);
}