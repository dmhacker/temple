#include <catch.hpp>
#include <metal.hpp>
#include <numerals.hpp>

TEST_CASE("Test cases")
{
    REQUIRE(temple::church0<metal::inc, metal::number<0>>() == 0);
    REQUIRE(temple::church1<metal::inc, metal::number<0>>() == 1);
    REQUIRE(temple::church2<metal::inc, metal::number<0>>() == 2);
    REQUIRE(temple::church3<metal::inc, metal::number<0>>() == 3);
    REQUIRE(temple::church4<metal::inc, metal::number<0>>() == 4);
    REQUIRE(temple::church5<metal::inc, metal::number<0>>() == 5);
    REQUIRE(metal::same<temple::apply_binary<temple::add, temple::church3, temple::church4>::church<metal::inc, metal::number<0>>, 
            temple::apply_binary<temple::add, temple::church4, temple::church3>::church<metal::inc, metal::number<0>>>());
    REQUIRE(metal::same<temple::apply_unary<temple::inc, temple::church4>::church<metal::inc, metal::number<0>>, 
            temple::church5<metal::inc, metal::number<0>>>());
}
