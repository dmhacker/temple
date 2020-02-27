#include <catch.hpp>
#include <metal.hpp>
#include <temple/numerals.hpp>

template <class n>
using ftst = metal::inc<n>;

using xtst = metal::number<0>;

TEST_CASE("Test cases")
{
    // Test church numerals from 0 to 10
    REQUIRE(temple::church0<ftst, xtst>() == 0);
    REQUIRE(temple::church1<ftst, xtst>() == 1);
    REQUIRE(temple::church2<ftst, xtst>() == 2);
    REQUIRE(temple::church3<ftst, xtst>() == 3);
    REQUIRE(temple::church4<ftst, xtst>() == 4);
    REQUIRE(temple::church5<ftst, xtst>() == 5);
    REQUIRE(temple::church6<ftst, xtst>() == 6);
    REQUIRE(temple::church7<ftst, xtst>() == 7);

    // Test arbitrary church numerals (n specified as integer literal)
    REQUIRE(temple::church<1000, metal::inc, metal::number<0>>() == 1000);

    // Test addition operation
    REQUIRE(metal::same<temple::apply_binary<temple::add, temple::church3, temple::church4>::type<ftst, xtst>,
        temple::apply_binary<temple::add, temple::church4, temple::church3>::type<ftst, xtst>>());

    // Test increment operation
    REQUIRE(metal::same<temple::apply_unary<temple::inc, temple::church4>::type<ftst, xtst>,
        temple::church5<ftst, xtst>>());
}
