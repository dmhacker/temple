#include <catch.hpp>
#include <metal.hpp>
#include <numerals.hpp>

TEST_CASE("Test cases")
{
    // Test church numerals from 0 to 10
    REQUIRE(temple::church0<metal::inc, metal::number<0>>() == 0);
    REQUIRE(temple::church1<metal::inc, metal::number<0>>() == 1);
    REQUIRE(temple::church2<metal::inc, metal::number<0>>() == 2);
    REQUIRE(temple::church3<metal::inc, metal::number<0>>() == 3);
    REQUIRE(temple::church4<metal::inc, metal::number<0>>() == 4);
    REQUIRE(temple::church5<metal::inc, metal::number<0>>() == 5);
    REQUIRE(temple::church6<metal::inc, metal::number<0>>() == 6);
    REQUIRE(temple::church7<metal::inc, metal::number<0>>() == 7);
    REQUIRE(temple::church4<metal::not_, metal::false_>() == false);
    REQUIRE(temple::church5<metal::not_, metal::false_>() == true);

    // Test arbitrary church numerals (n specified as integer literal)
    REQUIRE(temple::churchk<10000, metal::inc, metal::number<0>>() == 10000);

    // Test addition operation
    REQUIRE(metal::same<temple::apply_binary<temple::add, temple::church3, temple::church4>::type<metal::inc, metal::number<0>>, 
            temple::apply_binary<temple::add, temple::church4, temple::church3>::type<metal::inc, metal::number<0>>>());

    // Test increment operation
    REQUIRE(metal::same<temple::apply_unary<temple::inc, temple::church4>::type<metal::inc, metal::number<0>>, 
            temple::church5<metal::inc, metal::number<0>>>());
}
