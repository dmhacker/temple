# temple

[![Build Status](https://travis-ci.com/dmhacker/temple.svg?branch=master)](https://travis-ci.com/dmhacker/temple)

---

church numerals + template metaprogramming = temple

---

[Church numerals](https://en.wikipedia.org/wiki/Church_encoding) in lambda calculus are
a representation of the natural numbers using only functions. More specifically,
the nth natural number is represented as an n-fold application of a 
function __f__ to an argument __x__. For example, the 4th Church numeral is equal to:

```
f (f (f (f x)))
```

Using only C++11 templates, it's possible to construct and use Church numerals!
Specifically, you can do stuff like:

```cpp
template <class t>
using wrap_vector = std::vector<t>;

template <class cn, class base>
using wrap_vectors = temple::compose<cn, temple::fbox<wrap_vector>, base>;

wrap_vectors<temple::numeral<4>, char> vec0;
// decltype(vec0) == std::vector<std::vector<std::vector<std::vector<char>>>>
```

It's also possible to use standard arthimetic operations to combine Church numerals.
They're all just types after all :)

```cpp
wrap_vectors<temple::add<temple::numeral<1>, temple::numeral<3>>, char> vec1;
wrap_vectors<temple::mul<temple::numeral<4>, temple::numeral<1>>, char> vec2;
wrap_vectors<temple::pow<temple::numeral<2>, temple::numeral<2>>, char> vec3;
wrap_vectors<temple::sub<temple::numeral<10>, temple::numeral<6>>, char> vec4;
// decltype(vec0) == decltype(vec1) == decltype(vec2) == decltype(vec3) == decltype(vec4)
```

The implementation can be found in __include/temple/numerals.hpp__. 
Tests are in the __tests__ directory. Temple itself has no external dependencies;
however, its tests use the [metal](https://github.com/brunocodutra/metal) metaprogramming library.
