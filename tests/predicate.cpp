#include <temple.hpp>
#include <metal.hpp>

#define IS_SAME_IMPL(...) static_assert(__VA_ARGS__, #__VA_ARGS__)
#define IS_SAME(...) IS_SAME_IMPL(std::is_same<__VA_ARGS__>::value)

template <class b>
using truthy = temple::if_<b, metal::true_, metal::false_>;

// Test isz predicate
IS_SAME(truthy<temple::isz<temple::numeral<0>>>, metal::true_);
IS_SAME(truthy<temple::isz<temple::numeral<1>>>, metal::false_);
IS_SAME(truthy<temple::isz<temple::numeral<2>>>, metal::false_);
IS_SAME(truthy<temple::isz<temple::numeral<3>>>, metal::false_);
IS_SAME(truthy<temple::isz<temple::numeral<4>>>, metal::false_);
IS_SAME(truthy<temple::isz<temple::numeral<10>>>, metal::false_);
IS_SAME(truthy<temple::isz<temple::numeral<38>>>, metal::false_);
IS_SAME(truthy<temple::isz<temple::numeral<100>>>, metal::false_);
