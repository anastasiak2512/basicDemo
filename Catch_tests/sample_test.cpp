#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "sample_lib.h"

TEST_CASE( "Life, the universe and everything", "[theAnswer]" ) {
    SECTION("In base 10") {
        CHECK(answer<int> == 54);
    }
    SECTION("In base 13") {
        CHECK(answer<Base<13>> == "42");
    }
}

TEST_CASE( "Another big question", "[theAnswer]" ) {
    SECTION("In base 10") {
        CHECK(answer<float> == 48);
    }
}