#include <catch.hpp>
#include <metal.hpp>
#include <temple/numerals.hpp>

template <class n>
using ITER = metal::add<n, metal::number<2>>;

using BASE = metal::number<0>;

template <template <class> class f, class x>
using church100 = temple::church<100, f, x>;

template <template <class> class f, class x>
using church99 = temple::church<99, f, x>;

template <template <template <class> class, class> class n>
using is_even = n<metal::not_, metal::true_>;

template <template <template <class> class, class> class n>
using is_odd = n<metal::not_, metal::false_>;

TEST_CASE("Test cases for Church numerals")
{
    // Test church numerals from 0 to 10
    REQUIRE(temple::church0<ITER, BASE>() == 0);
    REQUIRE(temple::church1<ITER, BASE>() == 2);
    REQUIRE(temple::church2<ITER, BASE>() == 4);
    REQUIRE(temple::church3<ITER, BASE>() == 6);
    REQUIRE(temple::church4<ITER, BASE>() == 8);
    REQUIRE(temple::church5<ITER, BASE>() == 10);
    REQUIRE(temple::church6<ITER, BASE>() == 12);
    REQUIRE(temple::church7<ITER, BASE>() == 14);
    REQUIRE(temple::church8<ITER, BASE>() == 16);
    REQUIRE(temple::church9<ITER, BASE>() == 18);

    // Test arbitrary church numerals (n specified as integer literal)
    REQUIRE(church99<ITER, BASE>() == 198);
    REQUIRE(church100<ITER, BASE>() == 200);

    // Test parity of numerals
    REQUIRE(is_odd<temple::church1>());
    REQUIRE(is_even<temple::church2>());
    REQUIRE(is_odd<temple::church3>());
    REQUIRE(is_even<temple::church4>());
    REQUIRE(is_odd<temple::church5>());
    REQUIRE(is_even<temple::church6>());
    REQUIRE(is_odd<church99>());
    REQUIRE(is_even<church100>());

    // Test increment operation
    REQUIRE(metal::same<temple::inc<temple::church0, ITER, BASE>,
        temple::church1<ITER, BASE>>());
    REQUIRE(metal::same<temple::inc<temple::church1, ITER, BASE>,
        temple::church2<ITER, BASE>>());
    REQUIRE(metal::same<temple::inc<temple::church4, ITER, BASE>,
        temple::church5<ITER, BASE>>());
    REQUIRE(metal::same<temple::inc<church99, ITER, BASE>,
        church100<ITER, BASE>>());

    // Test decrement operation
    REQUIRE(metal::same<temple::dec<temple::church0, ITER, BASE>,
        temple::church0<ITER, BASE>>());
    REQUIRE(metal::same<temple::dec<temple::church1, ITER, BASE>,
        temple::church0<ITER, BASE>>());
    REQUIRE(metal::same<temple::dec<temple::church2, ITER, BASE>,
        temple::church1<ITER, BASE>>());
    REQUIRE(metal::same<temple::dec<church100, ITER, BASE>,
        church99<ITER, BASE>>());

    // Test addition operation
    REQUIRE(metal::same<temple::add<temple::church3, temple::church4, ITER, BASE>,
        temple::church7<ITER, BASE>>());
    REQUIRE(metal::same<temple::add<temple::church3, temple::church4, ITER, BASE>,
        temple::add<temple::church4, temple::church3, ITER, BASE>>());
    REQUIRE(metal::same<temple::add<temple::church0, temple::church0, ITER, BASE>,
        temple::church0<ITER, BASE>>());
    REQUIRE(metal::same<temple::add<temple::church4, temple::church4, ITER, BASE>,
        temple::church8<ITER, BASE>>());
    REQUIRE(metal::same<temple::add<temple::church3, temple::church6, ITER, BASE>,
        temple::church9<ITER, BASE>>());

    // Test multiplication operation
    REQUIRE(metal::same<temple::mul<temple::church2, temple::church4, ITER, BASE>,
        temple::church8<ITER, BASE>>());
    REQUIRE(metal::same<temple::mul<temple::church4, temple::church2, ITER, BASE>,
        temple::church8<ITER, BASE>>());
    REQUIRE(metal::same<temple::mul<temple::church1, temple::church6, ITER, BASE>,
        temple::church6<ITER, BASE>>());
    REQUIRE(metal::same<temple::mul<temple::church6, temple::church1, ITER, BASE>,
        temple::church6<ITER, BASE>>());
    REQUIRE(metal::same<temple::mul<temple::church0, temple::church8, ITER, BASE>,
        temple::church0<ITER, BASE>>());
    REQUIRE(metal::same<temple::mul<temple::church8, temple::church0, ITER, BASE>,
        temple::church0<ITER, BASE>>());

    // Test subtraction operation
    REQUIRE(metal::same<temple::sub<temple::church0, temple::church0, ITER, BASE>,
        temple::church0<ITER, BASE>>());
    REQUIRE(metal::same<temple::sub<temple::church0, temple::church5, ITER, BASE>,
        temple::church0<ITER, BASE>>());
    REQUIRE(metal::same<temple::sub<temple::church4, temple::church5, ITER, BASE>,
        temple::church0<ITER, BASE>>());
    REQUIRE(metal::same<temple::sub<temple::church5, temple::church5, ITER, BASE>,
        temple::church0<ITER, BASE>>());
    REQUIRE(metal::same<temple::sub<church100, church99, ITER, BASE>,
        temple::church1<ITER, BASE>>());
    REQUIRE(metal::same<temple::sub<church100, temple::church1, ITER, BASE>,
        church99<ITER, BASE>>());
    REQUIRE(metal::same<temple::sub<temple::church7, temple::church2, ITER, BASE>,
        temple::church5<ITER, BASE>>());
    REQUIRE(metal::same<temple::sub<temple::church4, temple::church1, ITER, BASE>,
        temple::dec<temple::church4, ITER, BASE>>());

    // Test exponentation operation
    REQUIRE(metal::same<temple::pow<temple::church1, temple::church0, ITER, BASE>,
        temple::church1<ITER, BASE>>());
    REQUIRE(metal::same<temple::pow<church100, temple::church0, ITER, BASE>,
        temple::church1<ITER, BASE>>());
    REQUIRE(metal::same<temple::pow<temple::church1, temple::church1, ITER, BASE>,
        temple::church1<ITER, BASE>>());
    REQUIRE(metal::same<temple::pow<church100, temple::church1, ITER, BASE>,
        church100<ITER, BASE>>());
    REQUIRE(metal::same<temple::pow<temple::church3, temple::church2, ITER, BASE>,
        temple::church9<ITER, BASE>>());
    REQUIRE(metal::same<temple::pow<temple::church2, temple::church3, ITER, BASE>,
        temple::church8<ITER, BASE>>());
    REQUIRE(metal::same<temple::pow<temple::church1, church100, ITER, BASE>,
        temple::church1<ITER, BASE>>());
    REQUIRE(metal::same<temple::pow<temple::church2, temple::church2, ITER, BASE>,
        temple::church4<ITER, BASE>>());
    REQUIRE(metal::same<temple::pow<church100, temple::church2, ITER, BASE>,
        temple::sqr<church100, ITER, BASE>>());
}
