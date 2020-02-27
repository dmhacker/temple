#include <catch.hpp>
#include <metal.hpp>
#include <temple/numerals.hpp>

template <class n>
using ftst = metal::inc<n>;

using xtst = metal::number<0>;

template <template <class> class f, class x>
using church100 = temple::church<100, f, x>;

template <template <class> class f, class x>
using church99 = temple::church<99, f, x>;

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
    REQUIRE(temple::church8<ftst, xtst>() == 8);
    REQUIRE(temple::church9<ftst, xtst>() == 9);

    // Test arbitrary church numerals (n specified as integer literal)
    REQUIRE(church99<metal::inc, metal::number<0>>() == 99);
    REQUIRE(church100<metal::inc, metal::number<0>>() == 100);

    // Test increment operation
    REQUIRE(metal::same<temple::inc<temple::church0, ftst, xtst>,
        temple::church1<ftst, xtst>>());
    REQUIRE(metal::same<temple::inc<temple::church1, ftst, xtst>,
        temple::church2<ftst, xtst>>());
    REQUIRE(metal::same<temple::inc<temple::church4, ftst, xtst>,
        temple::church5<ftst, xtst>>());
    REQUIRE(metal::same<temple::inc<church99, ftst, xtst>,
        church100<ftst, xtst>>());

    // Test decrement operation
    REQUIRE(metal::same<temple::dec<temple::church0, ftst, xtst>,
        temple::church0<ftst, xtst>>());
    REQUIRE(metal::same<temple::dec<temple::church1, ftst, xtst>,
        temple::church0<ftst, xtst>>());
    REQUIRE(metal::same<temple::dec<temple::church2, ftst, xtst>,
        temple::church1<ftst, xtst>>());
    REQUIRE(metal::same<temple::dec<church100, ftst, xtst>,
        church99<ftst, xtst>>());

    // Test addition operation
    REQUIRE(metal::same<temple::add<temple::church3, temple::church4, ftst, xtst>,
        temple::church7<ftst, xtst>>());
    REQUIRE(metal::same<temple::add<temple::church3, temple::church4, ftst, xtst>,
        temple::add<temple::church4, temple::church3, ftst, xtst>>());
    REQUIRE(metal::same<temple::add<temple::church0, temple::church0, ftst, xtst>,
        temple::church0<ftst, xtst>>());
    REQUIRE(metal::same<temple::add<temple::church4, temple::church4, ftst, xtst>,
        temple::church8<ftst, xtst>>());
    REQUIRE(metal::same<temple::add<temple::church3, temple::church6, ftst, xtst>,
        temple::church9<ftst, xtst>>());

    // Test multiplication operation
    REQUIRE(metal::same<temple::mul<temple::church2, temple::church4, ftst, xtst>,
        temple::church8<ftst, xtst>>());
    REQUIRE(metal::same<temple::mul<temple::church4, temple::church2, ftst, xtst>,
        temple::church8<ftst, xtst>>());
    REQUIRE(metal::same<temple::mul<temple::church1, temple::church6, ftst, xtst>,
        temple::church6<ftst, xtst>>());
    REQUIRE(metal::same<temple::mul<temple::church6, temple::church1, ftst, xtst>,
        temple::church6<ftst, xtst>>());
    REQUIRE(metal::same<temple::mul<temple::church0, temple::church8, ftst, xtst>,
        temple::church0<ftst, xtst>>());
    REQUIRE(metal::same<temple::mul<temple::church8, temple::church0, ftst, xtst>,
        temple::church0<ftst, xtst>>());

    // Test subtraction operation
    REQUIRE(metal::same<temple::sub<temple::church0, temple::church0, ftst, xtst>,
        temple::church0<ftst, xtst>>());
    REQUIRE(metal::same<temple::sub<temple::church0, temple::church5, ftst, xtst>,
        temple::church0<ftst, xtst>>());
    REQUIRE(metal::same<temple::sub<temple::church4, temple::church5, ftst, xtst>,
        temple::church0<ftst, xtst>>());
    REQUIRE(metal::same<temple::sub<temple::church5, temple::church5, ftst, xtst>,
        temple::church0<ftst, xtst>>());
    REQUIRE(metal::same<temple::sub<church100, church99, ftst, xtst>,
        temple::church1<ftst, xtst>>());
    REQUIRE(metal::same<temple::sub<church100, temple::church1, ftst, xtst>,
        church99<ftst, xtst>>());
    REQUIRE(metal::same<temple::sub<temple::church7, temple::church2, ftst, xtst>,
        temple::church5<ftst, xtst>>());
    REQUIRE(metal::same<temple::sub<temple::church4, temple::church1, ftst, xtst>,
        temple::dec<temple::church4, ftst, xtst>>());
}
