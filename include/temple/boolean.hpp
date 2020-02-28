#ifndef TEMPLE_BOOLEAN_HPP
#define TEMPLE_BOOLEAN_HPP

#include "box.hpp"

namespace temple {

namespace detail {
    template <class a, class b>
    using _true = a;

    template <class a, class b>
    using _false = b;

    template <class p, class a, class b>
    struct _if;

    template <class p, class q>
    struct _and;

    template <class p, class q>
    struct _or;

    template <class p>
    struct _not;

    template <class p, class q>
    struct _xor;
}

using true_ = bbox<detail::_true>;

using false_ = bbox<detail::_false>;

template <class p, class a, class b>
using if_ = typename detail::_if<p, a, b>::type;

template <class p, class q>
using and_ = typename detail::_and<p, q>::type;

template <class p, class q>
using or_ = typename detail::_or<p, q>::type;

template <class p>
using not_ = typename detail::_not<p>::type;

template <class p, class q>
using xor_ = typename detail::_xor<p, q>::type;

namespace detail {
    template <class p, class a, class b>
    struct _if {
    };

    template <template <class, class> class p, class a, class b>
    struct _if<bbox<p>, a, b> {
        using type = p<a, b>;
    };

    template <class p, class q>
    struct _and {
    };

    template <template <class, class> class p,
        template <class, class> class q>
    struct _and<bbox<p>, bbox<q>> {
        using type = p<bbox<q>, false_>;
    };

    template <class p, class q>
    struct _or {
    };

    template <template <class, class> class p,
        template <class, class> class q>
    struct _or<bbox<p>, bbox<q>> {
        using type = p<true_, bbox<p>>;
    };

    template <class p>
    struct _not {
    };

    template <template <class, class> class p>
    struct _not<bbox<p>> {
        using type = p<false_, true_>;
    };

    template <class p, class q>
    struct _xor {
    };

    template <template <class, class> class p,
        template <class, class> class q>
    struct _xor<bbox<p>, bbox<q>> {
        using type = p<not_<bbox<q>>, bbox<q>>;
    };
}

}

#endif
