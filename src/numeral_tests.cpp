#include <metal.hpp>
#include <temple.hpp>
#include <vector>

#define IS_SAME_IMPL(...) static_assert(__VA_ARGS__, #__VA_ARGS__)
#define IS_SAME(...) IS_SAME_IMPL(std::is_same<__VA_ARGS__>::value)

using base = metal::number<0>;

using iter = temple::fbox<metal::inc>;

template <template <template <class> class, class> class n>
using is_even = n<metal::not_, metal::true_>;

template <template <template <class> class, class> class n>
using is_odd = n<metal::not_, metal::false_>;

template <class t>
using vectorize = std::vector<t>;

// Test increment operation
IS_SAME(temple::churchify<temple::inc<temple::church<0>>, iter, base>,
    temple::churchify<temple::church<1>, iter, base>);
IS_SAME(temple::churchify<temple::inc<temple::church<1>>, iter, base>,
    temple::churchify<temple::church<2>, iter, base>);
IS_SAME(temple::churchify<temple::inc<temple::church<2>>, iter, base>,
    temple::churchify<temple::church<3>, iter, base>);
IS_SAME(temple::churchify<temple::inc<temple::church<34>>, iter, base>,
    temple::churchify<temple::church<35>, iter, base>);
IS_SAME(temple::churchify<temple::inc<temple::church<99>>, iter, base>,
    temple::churchify<temple::church<100>, iter, base>);

// Test addition operation
IS_SAME(temple::churchify<temple::add<temple::church<3>, temple::church<4>>, iter, base>,
    temple::churchify<temple::church<7>, iter, base>);
IS_SAME(temple::churchify<temple::add<temple::church<4>, temple::church<3>>, iter, base>,
    temple::churchify<temple::church<7>, iter, base>);
IS_SAME(temple::churchify<temple::add<temple::church<0>, temple::church<0>>, iter, base>,
    temple::churchify<temple::church<0>, iter, base>);
IS_SAME(temple::churchify<temple::add<temple::church<4>, temple::church<4>>, iter, base>,
    temple::churchify<temple::church<8>, iter, base>);
IS_SAME(temple::churchify<temple::add<temple::church<6>, temple::church<3>>, iter, base>,
    temple::churchify<temple::church<9>, iter, base>);
IS_SAME(temple::churchify<temple::add<temple::church<32>, temple::church<33>>, iter, base>,
    temple::churchify<temple::church<65>, iter, base>);

// Test multiplication operation
IS_SAME(temple::churchify<temple::mul<temple::church<2>, temple::church<4>>, iter, base>,
    temple::churchify<temple::church<8>, iter, base>);
IS_SAME(temple::churchify<temple::mul<temple::church<1>, temple::church<6>>, iter, base>,
    temple::churchify<temple::church<6>, iter, base>);
IS_SAME(temple::churchify<temple::mul<temple::church<6>, temple::church<1>>, iter, base>,
    temple::churchify<temple::church<6>, iter, base>);
IS_SAME(temple::churchify<temple::mul<temple::church<8>, temple::church<0>>, iter, base>,
    temple::churchify<temple::church<0>, iter, base>);
IS_SAME(temple::churchify<temple::mul<temple::church<0>, temple::church<8>>, iter, base>,
    temple::churchify<temple::church<0>, iter, base>);
IS_SAME(temple::churchify<temple::mul<temple::church<7>, temple::church<12>>, iter, base>,
    temple::churchify<temple::church<84>, iter, base>);

// Test exponentation operation
IS_SAME(temple::churchify<temple::pow<temple::church<1>, temple::church<0>>, iter, base>,
    temple::churchify<temple::church<1>,iter, base>);
IS_SAME(temple::churchify<temple::pow<temple::church<100>, temple::church<0>>, iter, base>,
    temple::churchify<temple::church<1>,iter, base>);
IS_SAME(temple::churchify<temple::pow<temple::church<1>, temple::church<1>>, iter, base>,
    temple::churchify<temple::church<1>,iter, base>);
IS_SAME(temple::churchify<temple::pow<temple::church<100>, temple::church<1>>, iter, base>,
    temple::churchify<temple::church<100>,iter, base>);
IS_SAME(temple::churchify<temple::pow<temple::church<3>, temple::church<2>>, iter, base>,
    temple::churchify<temple::church<9>,iter, base>);
IS_SAME(temple::churchify<temple::pow<temple::church<2>, temple::church<3>>, iter, base>,
    temple::churchify<temple::church<8>,iter, base>);
IS_SAME(temple::churchify<temple::pow<temple::church<1>, temple::church<100>>, iter, base>,
    temple::churchify<temple::church<1>,iter, base>);
IS_SAME(temple::churchify<temple::pow<temple::church<2>, temple::church<2>>, iter, base>,
    temple::churchify<temple::church<4>,iter, base>);
IS_SAME(temple::churchify<temple::pow<temple::church<4>, temple::church<2>>, iter, base>,
    temple::churchify<temple::church<16>,iter, base>);

/*
// Test church numerals from 0 to 10
static_assert(temple::church0<iter, base>() == 0);
static_assert(temple::church1<iter, base>() == 2);
static_assert(temple::church2<iter, base>() == 4);
static_assert(temple::church3<iter, base>() == 6);
static_assert(temple::church4<iter, base>() == 8);
static_assert(temple::church5<iter, base>() == 10);
static_assert(temple::church6<iter, base>() == 12);
static_assert(temple::church7<iter, base>() == 14);
static_assert(temple::church8<iter, base>() == 16);
static_assert(temple::church9<iter, base>() == 18);

// Test arbitrary church numerals (n specified as integer literal)
static_assert(church99<iter, base>() == 198);
static_assert(church100<iter, base>() == 200);

// Try using a common type like std::vector
static_assert(metal::same<temple::church0<vectorize, char>, char>());
static_assert(metal::same<temple::church1<vectorize, char>, std::vector<char>>());
static_assert(metal::same<temple::church5<vectorize, char>, 
        std::vector<std::vector<std::vector<std::vector<std::vector<char>>>>>>());

// Test parity of numerals
static_assert(is_odd<temple::church1>());
static_assert(is_even<temple::church2>());
static_assert(is_odd<temple::church3>());
static_assert(is_even<temple::church4>());
static_assert(is_odd<temple::church5>());
static_assert(is_even<temple::church6>());
static_assert(is_odd<church99>());
static_assert(is_even<church100>());
*/

/* // Test decrement operation */
/* static_assert(metal::same<temple::dec<temple::church0, iter, base>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::dec<temple::church1, iter, base>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::dec<temple::church2, iter, base>, */
/*     temple::church1<iter, base>>()); */
/* static_assert(metal::same<temple::dec<church100, iter, base>, */
/*     church99<iter, base>>()); */

/* // Test subtraction operation */
/* static_assert(metal::same<temple::sub<temple::church0, temple::church0, iter, base>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church0, temple::church5, iter, base>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church4, temple::church5, iter, base>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church5, temple::church5, iter, base>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::sub<church100, church99, iter, base>, */
/*     temple::church1<iter, base>>()); */
/* static_assert(metal::same<temple::sub<church100, temple::church1, iter, base>, */
/*     church99<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church7, temple::church2, iter, base>, */
/*     temple::church5<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church4, temple::church1, iter, base>, */
/*     temple::dec<temple::church4, iter, base>>()); */
