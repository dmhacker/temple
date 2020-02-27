#ifndef TEMPLE_PAIR_HPP
#define TEMPLE_PAIR_HPP

#include <cstdint>

namespace temple {

template <class l, class r>
struct pair {
    using left = l;
    using right = r;
};

template <class p>
using first = typename p::left;

template <class p>
using second = typename p::right;

}

#endif
