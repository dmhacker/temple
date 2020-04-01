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

// Test eq predicate
IS_SAME(truthy<temple::eq<temple::numeral<0>, temple::numeral<0>>>, metal::true_);
IS_SAME(truthy<temple::eq<temple::numeral<3>, temple::numeral<3>>>, metal::true_);
IS_SAME(truthy<temple::eq<temple::numeral<39>, temple::numeral<39>>>, metal::true_);
IS_SAME(truthy<temple::eq<temple::numeral<73>, temple::numeral<73>>>, metal::true_);
IS_SAME(truthy<temple::eq<temple::numeral<13>, temple::numeral<13>>>, metal::true_);
IS_SAME(truthy<temple::eq<temple::numeral<22>, temple::numeral<22>>>, metal::true_);
IS_SAME(truthy<temple::eq<temple::numeral<0>, temple::numeral<8>>>, metal::false_);
IS_SAME(truthy<temple::eq<temple::numeral<3>, temple::numeral<1>>>, metal::false_);
IS_SAME(truthy<temple::eq<temple::numeral<39>, temple::numeral<9>>>, metal::false_);
IS_SAME(truthy<temple::eq<temple::numeral<73>, temple::numeral<70>>>, metal::false_);
IS_SAME(truthy<temple::eq<temple::numeral<13>, temple::numeral<5>>>, metal::false_);
IS_SAME(truthy<temple::eq<temple::numeral<22>, temple::numeral<2>>>, metal::false_);

// Test leq predicate
IS_SAME(truthy<temple::leq<temple::numeral<0>, temple::numeral<0>>>, metal::true_);
IS_SAME(truthy<temple::leq<temple::numeral<7>, temple::numeral<7>>>, metal::true_);
IS_SAME(truthy<temple::leq<temple::numeral<30>, temple::numeral<30>>>, metal::true_);
IS_SAME(truthy<temple::leq<temple::numeral<88>, temple::numeral<88>>>, metal::true_);
IS_SAME(truthy<temple::leq<temple::numeral<0>, temple::numeral<2>>>, metal::true_);
IS_SAME(truthy<temple::leq<temple::numeral<0>, temple::numeral<100>>>, metal::true_);
IS_SAME(truthy<temple::leq<temple::numeral<29>, temple::numeral<30>>>, metal::true_);
IS_SAME(truthy<temple::leq<temple::numeral<21>, temple::numeral<92>>>, metal::true_);
IS_SAME(truthy<temple::leq<temple::numeral<1>, temple::numeral<0>>>, metal::false_);
IS_SAME(truthy<temple::leq<temple::numeral<10>, temple::numeral<0>>>, metal::false_);
IS_SAME(truthy<temple::leq<temple::numeral<10>, temple::numeral<9>>>, metal::false_);
IS_SAME(truthy<temple::leq<temple::numeral<100>, temple::numeral<23>>>, metal::false_);

// Test geq predicate
IS_SAME(truthy<temple::geq<temple::numeral<0>, temple::numeral<0>>>, metal::true_);
IS_SAME(truthy<temple::geq<temple::numeral<7>, temple::numeral<7>>>, metal::true_);
IS_SAME(truthy<temple::geq<temple::numeral<30>, temple::numeral<30>>>, metal::true_);
IS_SAME(truthy<temple::geq<temple::numeral<88>, temple::numeral<88>>>, metal::true_);
IS_SAME(truthy<temple::geq<temple::numeral<0>, temple::numeral<2>>>, metal::false_);
IS_SAME(truthy<temple::geq<temple::numeral<0>, temple::numeral<100>>>, metal::false_);
IS_SAME(truthy<temple::geq<temple::numeral<29>, temple::numeral<30>>>, metal::false_);
IS_SAME(truthy<temple::geq<temple::numeral<21>, temple::numeral<92>>>, metal::false_);
IS_SAME(truthy<temple::geq<temple::numeral<1>, temple::numeral<0>>>, metal::true_);
IS_SAME(truthy<temple::geq<temple::numeral<10>, temple::numeral<0>>>, metal::true_);
IS_SAME(truthy<temple::geq<temple::numeral<10>, temple::numeral<9>>>, metal::true_);
IS_SAME(truthy<temple::geq<temple::numeral<100>, temple::numeral<23>>>, metal::true_);

// Test lt predicate
IS_SAME(truthy<temple::lt<temple::numeral<0>, temple::numeral<0>>>, metal::false_);
IS_SAME(truthy<temple::lt<temple::numeral<7>, temple::numeral<7>>>, metal::false_);
IS_SAME(truthy<temple::lt<temple::numeral<30>, temple::numeral<30>>>, metal::false_);
IS_SAME(truthy<temple::lt<temple::numeral<88>, temple::numeral<88>>>, metal::false_);
IS_SAME(truthy<temple::lt<temple::numeral<0>, temple::numeral<2>>>, metal::true_);
IS_SAME(truthy<temple::lt<temple::numeral<0>, temple::numeral<100>>>, metal::true_);
IS_SAME(truthy<temple::lt<temple::numeral<29>, temple::numeral<30>>>, metal::true_);
IS_SAME(truthy<temple::lt<temple::numeral<21>, temple::numeral<92>>>, metal::true_);
IS_SAME(truthy<temple::lt<temple::numeral<1>, temple::numeral<0>>>, metal::false_);
IS_SAME(truthy<temple::lt<temple::numeral<10>, temple::numeral<0>>>, metal::false_);
IS_SAME(truthy<temple::lt<temple::numeral<10>, temple::numeral<9>>>, metal::false_);
IS_SAME(truthy<temple::lt<temple::numeral<100>, temple::numeral<23>>>, metal::false_);

// Test gt predicate
IS_SAME(truthy<temple::gt<temple::numeral<0>, temple::numeral<0>>>, metal::false_);
IS_SAME(truthy<temple::gt<temple::numeral<7>, temple::numeral<7>>>, metal::false_);
IS_SAME(truthy<temple::gt<temple::numeral<30>, temple::numeral<30>>>, metal::false_);
IS_SAME(truthy<temple::gt<temple::numeral<88>, temple::numeral<88>>>, metal::false_);
IS_SAME(truthy<temple::gt<temple::numeral<0>, temple::numeral<2>>>, metal::false_);
IS_SAME(truthy<temple::gt<temple::numeral<0>, temple::numeral<100>>>, metal::false_);
IS_SAME(truthy<temple::gt<temple::numeral<29>, temple::numeral<30>>>, metal::false_);
IS_SAME(truthy<temple::gt<temple::numeral<21>, temple::numeral<92>>>, metal::false_);
IS_SAME(truthy<temple::gt<temple::numeral<1>, temple::numeral<0>>>, metal::true_);
IS_SAME(truthy<temple::gt<temple::numeral<10>, temple::numeral<0>>>, metal::true_);
IS_SAME(truthy<temple::gt<temple::numeral<10>, temple::numeral<9>>>, metal::true_);
IS_SAME(truthy<temple::gt<temple::numeral<100>, temple::numeral<23>>>, metal::true_);
