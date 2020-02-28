#ifndef TEMPLE_PREDICATE_HPP
#define TEMPLE_PREDICATE_HPP

#include "boolean.hpp"
#include "box.hpp"
#include "numeral.hpp"

namespace temple {

namespace detail {
    template <class n>
    struct _isz;
}

template <class n>
using isz = typename detail::_isz<n>::type;

template <class m, class n>
using leq = isz<sub<m, n>>;

template <class m, class n>
using geq = leq<n, m>;

template <class m, class n>
using gt = not_<leq<m, n>>;

template <class m, class n>
using lt = gt<n, m>;

template <class m, class n>
using eql = and_<leq<m, n>, leq<n, m>>;

namespace detail {
    template <class n>
    struct _isz {
    };

    template <template <template <class> class, class> class n>
    struct _isz<nbox<n>> {
        template <class cn>
        using iter = false_;

        using type = n<iter, true_>;
    };
}

}

#endif
