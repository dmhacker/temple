#include <metal.hpp>
#include <temple.hpp>
#include <vector>

#define IS_SAME_IMPL(...) static_assert(__VA_ARGS__, #__VA_ARGS__)
#define IS_SAME(...) IS_SAME_IMPL(std::is_same<__VA_ARGS__>::value)

template <class cn>
using order = temple::compose<cn, temple::fbox<metal::inc>, metal::number<0>>;

template <class cn>
using is_even = temple::compose<cn, temple::fbox<metal::not_>, metal::true_>;

template <class t>
using wrap_vector = std::vector<t>;

template <class cn, class base>
using wrap_vectors = temple::compose<cn, temple::fbox<wrap_vector>, base>;

// Basic interpretation of Church numerals works correctly
IS_SAME(wrap_vectors<temple::numeral<0>, char>, char);
IS_SAME(wrap_vectors<temple::numeral<1>, char>, std::vector<char>);
IS_SAME(wrap_vectors<temple::numeral<2>, char>,
    std::vector<std::vector<char>>);
IS_SAME(wrap_vectors<temple::numeral<3>, char>,
    std::vector<std::vector<std::vector<char>>>);
IS_SAME(wrap_vectors<temple::numeral<4>, char>,
    std::vector<std::vector<std::vector<std::vector<char>>>>);
IS_SAME(wrap_vectors<temple::numeral<5>, char>,
    std::vector<std::vector<std::vector<std::vector<std::vector<char>>>>>);

// Test parity of Church numerals
IS_SAME(is_even<temple::numeral<0>>, metal::true_);
IS_SAME(is_even<temple::numeral<2>>, metal::true_);
IS_SAME(is_even<temple::numeral<4>>, metal::true_);
IS_SAME(is_even<temple::numeral<64>>, metal::true_);
IS_SAME(is_even<temple::numeral<192>>, metal::true_);
IS_SAME(is_even<temple::numeral<1>>, metal::false_);
IS_SAME(is_even<temple::numeral<3>>, metal::false_);
IS_SAME(is_even<temple::numeral<5>>, metal::false_);
IS_SAME(is_even<temple::numeral<123>>, metal::false_);
IS_SAME(is_even<temple::numeral<201>>, metal::false_);

// Test increment operation
IS_SAME(order<temple::inc<temple::numeral<0>>>,
    order<temple::numeral<1>>);
IS_SAME(order<temple::inc<temple::numeral<1>>>,
    order<temple::numeral<2>>);
IS_SAME(order<temple::inc<temple::numeral<2>>>,
    order<temple::numeral<3>>);
IS_SAME(order<temple::inc<temple::numeral<34>>>,
    order<temple::numeral<35>>);
IS_SAME(order<temple::inc<temple::numeral<35>>>,
    order<temple::numeral<36>>);

// Test addition operation
IS_SAME(order<temple::add<temple::numeral<3>, temple::numeral<4>>>,
    order<temple::numeral<7>>);
IS_SAME(order<temple::add<temple::numeral<4>, temple::numeral<3>>>,
    order<temple::numeral<7>>);
IS_SAME(order<temple::add<temple::numeral<0>, temple::numeral<0>>>,
    order<temple::numeral<0>>);
IS_SAME(order<temple::add<temple::numeral<4>, temple::numeral<4>>>,
    order<temple::numeral<8>>);
IS_SAME(order<temple::add<temple::numeral<6>, temple::numeral<3>>>,
    order<temple::numeral<9>>);
IS_SAME(order<temple::add<temple::numeral<32>, temple::numeral<33>>>,
    order<temple::numeral<65>>);

// Test multiplication operation
IS_SAME(order<temple::mul<temple::numeral<2>, temple::numeral<4>>>,
    order<temple::numeral<8>>);
IS_SAME(order<temple::mul<temple::numeral<1>, temple::numeral<6>>>,
    order<temple::numeral<6>>);
IS_SAME(order<temple::mul<temple::numeral<6>, temple::numeral<1>>>,
    order<temple::numeral<6>>);
IS_SAME(order<temple::mul<temple::numeral<8>, temple::numeral<0>>>,
    order<temple::numeral<0>>);
IS_SAME(order<temple::mul<temple::numeral<0>, temple::numeral<8>>>,
    order<temple::numeral<0>>);
IS_SAME(order<temple::mul<temple::numeral<7>, temple::numeral<12>>>,
    order<temple::numeral<84>>);

// Test squaring operation
IS_SAME(order<temple::sqr<temple::numeral<0>>>,
    order<temple::numeral<0>>);
IS_SAME(order<temple::sqr<temple::numeral<1>>>,
    order<temple::numeral<1>>);
IS_SAME(order<temple::sqr<temple::numeral<2>>>,
    order<temple::numeral<4>>);
IS_SAME(order<temple::sqr<temple::numeral<7>>>,
    order<temple::numeral<49>>);
IS_SAME(order<temple::sqr<temple::numeral<10>>>,
    order<temple::numeral<100>>);

// Test exponentation operation
IS_SAME(order<temple::pow<temple::numeral<1>, temple::numeral<0>>>,
    order<temple::numeral<1>>);
IS_SAME(order<temple::pow<temple::numeral<100>, temple::numeral<0>>>,
    order<temple::numeral<1>>);
IS_SAME(order<temple::pow<temple::numeral<1>, temple::numeral<1>>>,
    order<temple::numeral<1>>);
IS_SAME(order<temple::pow<temple::numeral<100>, temple::numeral<1>>>,
    order<temple::numeral<100>>);
IS_SAME(order<temple::pow<temple::numeral<3>, temple::numeral<2>>>,
    order<temple::numeral<9>>);
IS_SAME(order<temple::pow<temple::numeral<2>, temple::numeral<3>>>,
    order<temple::numeral<8>>);
IS_SAME(order<temple::pow<temple::numeral<1>, temple::numeral<100>>>,
    order<temple::numeral<1>>);
IS_SAME(order<temple::pow<temple::numeral<2>, temple::numeral<2>>>,
    order<temple::numeral<4>>);
IS_SAME(order<temple::pow<temple::numeral<4>, temple::numeral<2>>>,
    order<temple::numeral<16>>);

// Test decrement operation
IS_SAME(order<temple::dec<temple::numeral<0>>>,
    order<temple::numeral<0>>);
IS_SAME(order<temple::dec<temple::numeral<1>>>,
    order<temple::numeral<0>>);
IS_SAME(order<temple::dec<temple::numeral<2>>>,
    order<temple::numeral<1>>);
IS_SAME(order<temple::dec<temple::numeral<3>>>,
    order<temple::numeral<2>>);
IS_SAME(order<temple::dec<temple::numeral<34>>>,
    order<temple::numeral<33>>);
IS_SAME(order<temple::dec<temple::numeral<35>>>,
    order<temple::numeral<34>>);
IS_SAME(order<temple::dec<temple::numeral<99>>>,
    order<temple::numeral<98>>);

// Test subtraction operation
IS_SAME(order<temple::sub<temple::numeral<0>, temple::numeral<0>>>,
    order<temple::numeral<0>>);
IS_SAME(order<temple::sub<temple::numeral<3>, temple::numeral<4>>>,
    order<temple::numeral<0>>);
IS_SAME(order<temple::sub<temple::numeral<4>, temple::numeral<4>>>,
    order<temple::numeral<0>>);
IS_SAME(order<temple::sub<temple::numeral<4>, temple::numeral<3>>>,
    order<temple::numeral<1>>);
IS_SAME(order<temple::sub<temple::numeral<6>, temple::numeral<3>>>,
    order<temple::numeral<3>>);
IS_SAME(order<temple::sub<temple::numeral<100>, temple::numeral<33>>>,
    order<temple::numeral<67>>);
