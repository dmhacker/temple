#ifndef TEMPLE_DIVISION_HPP
#define TEMPLE_DIVISION_HPP

#include <cstdint>

#include "numeral.hpp"
#include "predicate.hpp"

namespace temple {

namespace detail {
    template <class m, class n>
    struct _div;
}

template <class m, class n>
using div = typename detail::_div<m, n>::type;

namespace detail {
    template <class m, class n>
    struct _div {
    };

    template <template <template <class> class, class> class m,
        template <template <class> class, class> class n>
    struct _div<nbox<m>, nbox<n>> {
        template <class accum>
        struct _iter {
            using type = if_<leq<mul<nbox<n>, inc<accum>>, nbox<m>>, inc<accum>, accum>;
        };

        template <class accum>
        using iter = typename _iter<accum>::type;

        using type = m<iter, numeral<0>>;
    };
}

}

#endif
