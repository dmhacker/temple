# temple

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
Interestingly, all numeric operations are implemented without using explicit recursion - 
this is accomplished by taking advantage of the properties of Church numerals.

All implementation details can be found in __include/temple__. 
Tests are in the __tests__ directory. Temple itself has no external dependencies;
however, some tests use the [metal](https://github.com/brunocodutra/metal) metaprogramming library.
