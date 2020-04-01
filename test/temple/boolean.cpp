#include <temple.hpp>
#include <type_traits>

#define IS_SAME_IMPL(...) static_assert(__VA_ARGS__, #__VA_ARGS__)
#define IS_SAME(...) IS_SAME_IMPL(std::is_same<__VA_ARGS__>::value)

// Basic interpretation of Church booleans works correctly
IS_SAME(temple::if_<temple::true_, char, int>, char);
IS_SAME(temple::if_<temple::false_, char, int>, int);
IS_SAME(temple::if_<temple::true_, temple::true_, temple::false_>, temple::true_);
IS_SAME(temple::if_<temple::false_, temple::false_, temple::true_>, temple::true_);

// Test not operation
IS_SAME(temple::if_<temple::not_<temple::false_>, char, int>, char);
IS_SAME(temple::if_<temple::not_<temple::true_>, char, int>, int);
IS_SAME(temple::if_<temple::not_<temple::not_<temple::true_>>, char, int>, char);
IS_SAME(temple::if_<temple::not_<temple::not_<temple::false_>>, char, int>, int);

// Test and operation
IS_SAME(temple::if_<temple::and_<temple::false_, temple::false_>, char, int>, int);
IS_SAME(temple::if_<temple::and_<temple::true_, temple::false_>, char, int>, int);
IS_SAME(temple::if_<temple::and_<temple::false_, temple::true_>, char, int>, int);
IS_SAME(temple::if_<temple::and_<temple::true_, temple::true_>, char, int>, char);

// Test or operation
IS_SAME(temple::if_<temple::or_<temple::false_, temple::false_>, char, int>, int);
IS_SAME(temple::if_<temple::or_<temple::true_, temple::false_>, char, int>, char);
IS_SAME(temple::if_<temple::or_<temple::false_, temple::true_>, char, int>, char);
IS_SAME(temple::if_<temple::or_<temple::true_, temple::true_>, char, int>, char);

// Test xor operation
IS_SAME(temple::if_<temple::xor_<temple::false_, temple::false_>, char, int>, int);
IS_SAME(temple::if_<temple::xor_<temple::true_, temple::false_>, char, int>, char);
IS_SAME(temple::if_<temple::xor_<temple::false_, temple::true_>, char, int>, char);
IS_SAME(temple::if_<temple::xor_<temple::true_, temple::true_>, char, int>, int);
