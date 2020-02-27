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

temple::churchify<temple::church<4>, temple::fbox<wrap_vector>, char> vec0;
// decltype(vec0) == std::vector<std::vector<std::vector<std::vector<char>>>>
```

It's also possible to use standard arthimetic operations to combine Church numerals! 
They're all just types after all :)

```cpp
temple::churchify<temple::add<temple::church<1>, temple::church<3>>, temple::fbox<wrap_vector>, char> vec1;
temple::churchify<temple::mul<temple::church<4>, temple::church<1>>, temple::fbox<wrap_vector>, char> vec2;
temple::churchify<temple::pow<temple::church<2>, temple::church<2>>, temple::fbox<wrap_vector>, char> vec3;
temple::churchify<temple::sub<temple::church<10>, temple::church<6>>, temple::fbox<wrap_vector>, char> vec4;
// decltype(vec1) == decltype(vec2) == decltype(vec3) == decltype(vec4)
```

The implementation can be found in __include/temple/numerals.hpp__. 
Tests are in the __tests__ directory.
