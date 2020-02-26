#include <catch.hpp>
#include <metal.hpp>
#include <temple.hpp>

TEST_CASE("Test cases")
{
    REQUIRE(temple::add<temple::church4, temple::church3, metal::inc, metal::number<0>>() == 7);
}
