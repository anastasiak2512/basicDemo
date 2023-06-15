#include "catch2/catch_all.hpp"

TEST_CASE("fail_catch_test")
{
    REQUIRE(0==1);
}