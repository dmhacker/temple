#include <metal.hpp>
#include <temple.hpp>
#include <vector>

#define IS_SAME_IMPL(...) static_assert(__VA_ARGS__, #__VA_ARGS__)
#define IS_SAME(...) IS_SAME_IMPL(std::is_same<__VA_ARGS__>::value)

template <class cn>
using order = temple::churchify<cn, temple::fbox<metal::inc>, metal::number<0>>;

template <class cn>
using is_even = temple::churchify<cn, temple::fbox<metal::not_>, metal::true_>;

template <class t>
using wrap_vector = std::vector<t>;

template <class cn, class base>
using wrap_vectors = temple::churchify<cn, temple::fbox<wrap_vector>, base>;

// Basic interpretation of Church numerals works correctly
IS_SAME(wrap_vectors<temple::church<0>, char>, char);
IS_SAME(wrap_vectors<temple::church<1>, char>, std::vector<char>);
IS_SAME(wrap_vectors<temple::church<2>, char>,
    std::vector<std::vector<char>>);
IS_SAME(wrap_vectors<temple::church<3>, char>,
    std::vector<std::vector<std::vector<char>>>);
IS_SAME(wrap_vectors<temple::church<4>, char>,
    std::vector<std::vector<std::vector<std::vector<char>>>>);
IS_SAME(wrap_vectors<temple::church<5>, char>,
    std::vector<std::vector<std::vector<std::vector<std::vector<char>>>>>);

// Test parity of Church numerals
IS_SAME(is_even<temple::church<0>>, metal::true_);
IS_SAME(is_even<temple::church<2>>, metal::true_);
IS_SAME(is_even<temple::church<4>>, metal::true_);
IS_SAME(is_even<temple::church<64>>, metal::true_);
IS_SAME(is_even<temple::church<192>>, metal::true_);
IS_SAME(is_even<temple::church<1>>, metal::false_);
IS_SAME(is_even<temple::church<3>>, metal::false_);
IS_SAME(is_even<temple::church<5>>, metal::false_);
IS_SAME(is_even<temple::church<123>>, metal::false_);
IS_SAME(is_even<temple::church<201>>, metal::false_);

// Test increment operation
IS_SAME(order<temple::inc<temple::church<0>>>,
    order<temple::church<1>>);
IS_SAME(order<temple::inc<temple::church<1>>>,
    order<temple::church<2>>);
IS_SAME(order<temple::inc<temple::church<2>>>,
    order<temple::church<3>>);
IS_SAME(order<temple::inc<temple::church<34>>>,
    order<temple::church<35>>);
IS_SAME(order<temple::inc<temple::church<35>>>,
    order<temple::church<36>>);

// Test addition operation
IS_SAME(order<temple::add<temple::church<3>, temple::church<4>>>,
    order<temple::church<7>>);
IS_SAME(order<temple::add<temple::church<4>, temple::church<3>>>,
    order<temple::church<7>>);
IS_SAME(order<temple::add<temple::church<0>, temple::church<0>>>,
    order<temple::church<0>>);
IS_SAME(order<temple::add<temple::church<4>, temple::church<4>>>,
    order<temple::church<8>>);
IS_SAME(order<temple::add<temple::church<6>, temple::church<3>>>,
    order<temple::church<9>>);
IS_SAME(order<temple::add<temple::church<32>, temple::church<33>>>,
    order<temple::church<65>>);

// Test multiplication operation
IS_SAME(order<temple::mul<temple::church<2>, temple::church<4>>>,
    order<temple::church<8>>);
IS_SAME(order<temple::mul<temple::church<1>, temple::church<6>>>,
    order<temple::church<6>>);
IS_SAME(order<temple::mul<temple::church<6>, temple::church<1>>>,
    order<temple::church<6>>);
IS_SAME(order<temple::mul<temple::church<8>, temple::church<0>>>,
    order<temple::church<0>>);
IS_SAME(order<temple::mul<temple::church<0>, temple::church<8>>>,
    order<temple::church<0>>);
IS_SAME(order<temple::mul<temple::church<7>, temple::church<12>>>,
    order<temple::church<84>>);

// Test exponentation operation
IS_SAME(order<temple::pow<temple::church<1>, temple::church<0>>>,
    order<temple::church<1>>);
IS_SAME(order<temple::pow<temple::church<100>, temple::church<0>>>,
    order<temple::church<1>>);
IS_SAME(order<temple::pow<temple::church<1>, temple::church<1>>>,
    order<temple::church<1>>);
IS_SAME(order<temple::pow<temple::church<100>, temple::church<1>>>,
    order<temple::church<100>>);
IS_SAME(order<temple::pow<temple::church<3>, temple::church<2>>>,
    order<temple::church<9>>);
IS_SAME(order<temple::pow<temple::church<2>, temple::church<3>>>,
    order<temple::church<8>>);
IS_SAME(order<temple::pow<temple::church<1>, temple::church<100>>>,
    order<temple::church<1>>);
IS_SAME(order<temple::pow<temple::church<2>, temple::church<2>>>,
    order<temple::church<4>>);
IS_SAME(order<temple::pow<temple::church<4>, temple::church<2>>>,
    order<temple::church<16>>);

/* // Test decrement operation */
/* static_assert(metal::same<temple::dec<temple::church0>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::dec<temple::church1>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::dec<temple::church2>, */
/*     temple::church1<iter, base>>()); */
/* static_assert(metal::same<temple::dec<church100>, */
/*     church99<iter, base>>()); */

/* // Test subtraction operation */
/* static_assert(metal::same<temple::sub<temple::church0, temple::church0>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church0, temple::church5>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church4, temple::church5>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church5, temple::church5>, */
/*     temple::church0<iter, base>>()); */
/* static_assert(metal::same<temple::sub<church100, church99>, */
/*     temple::church1<iter, base>>()); */
/* static_assert(metal::same<temple::sub<church100, temple::church1>, */
/*     church99<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church7, temple::church2>, */
/*     temple::church5<iter, base>>()); */
/* static_assert(metal::same<temple::sub<temple::church4, temple::church1>, */
/*     temple::dec<temple::church4>>()); */
