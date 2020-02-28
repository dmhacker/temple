#ifndef TEMPLE_NUMERAL_HPP
#define TEMPLE_NUMERAL_HPP

#include <cstdint>

#include "box.hpp"
#include "pair.hpp"

namespace temple {

using int_ = uint32_t;

namespace detail {
    template <class n, class f, class x>
    struct _compose;

    template <class n>
    struct _inc;

    template <int_ k>
    struct _numeral;

    template <class m, class n>
    struct _add;

    template <class m, class n>
    struct _mul;

    template <class n, class p>
    struct _pow;

    template <class n>
    struct _dec;
}

template <class n, class f, class x>
using compose = typename detail::_compose<n, f, x>::type;

template <class n>
using inc = typename detail::_inc<n>::type;

template <int_ k>
using numeral = typename detail::_numeral<k>::type;

template <class m, class n>
using add = typename detail::_add<m, n>::type;

template <class m, class n>
using mul = typename detail::_mul<m, n>::type;

template <class n>
using sqr = mul<n, n>;

template <class n, class p>
using pow = typename detail::_pow<n, p>::type;

template <class n>
using dec = typename detail::_dec<n>::type;

/*
template <template <template <class> class, class> class n,
    template <class> class f, class x>
using dec = typename detail::_dec<n, f, x>::type;

template <template <template <class> class, class> class n,
    template <class> class f, class x>
using sqr = mul<n, n, f, x>;

template <template <template <class> class, class> class n,
    template <template <class> class, class> class m,
    template <class> class f, class x>
using sub = typename detail::_sub<n, m, f, x>::type;

template <template <template <class> class, class> class n,
    template <template <class> class, class> class p,
    template <class> class f, class x>
using pow = typename detail::_pow<n, p, f, x>::type;
*/

namespace detail {
    template <class n, class f, class x>
    struct _compose {
    };

    template <template <template <class> class, class> class n, template <class> class f, class x>
    struct _compose<nbox<n>, fbox<f>, x> {
        using type = n<f, x>;
    };

    template <class n>
    struct _inc {
    };

    template <template <template <class> class, class> class n>
    struct _inc<nbox<n>> {
        template <template <class> class f, class x>
        using result = f<n<f, x>>;

        using type = nbox<result>;
    };

    template <int_ k>
    struct _numeral {
        using type = inc<numeral<k - 1>>;
    };

    template <>
    struct _numeral<0> {
        template <template <class> class f, class x>
        using church0 = x;

        using type = nbox<church0>;
    };

    template <class m, class n>
    struct _add {
    };

    template <template <template <class> class, class> class m,
        template <template <class> class, class> class n>
    struct _add<nbox<m>, nbox<n>> {
        template <class accum>
        using iter = inc<accum>;

        using type =  m<iter, nbox<n>>;

        /* // Alternative approach: */
        /* template <template <class> class f, class x> */
        /* using result = m<f, n<f, x>>; */

        /* using type = nbox<result>; */
    };

    template <class m, class n>
    struct _mul {
    };

    template <template <template <class> class, class> class m,
        template <template <class> class, class> class n>
    struct _mul<nbox<m>, nbox<n>> {
        template <class accum>
        using iter = add<nbox<n>, accum>;

        using type = m<iter, numeral<0>>;
    };

    template <class n, class p>
    struct _pow {
    };

    template <template <template <class> class, class> class n,
        template <template <class> class, class> class p>
    struct _pow<nbox<n>, nbox<p>> {
        template <class accum>
        using iter = mul<nbox<n>, accum>;

        using type = p<iter, numeral<1>>;
    };

    template <class n>
    struct _dec {
    };

    template <template <template <class> class, class> class n>
    struct _dec<nbox<n>> {
        template <class p>
        using iter = pair<second<p>, inc<second<p>>>;

        using type = first<n<iter, pair<numeral<0>, numeral<0>>>>;
    };

    /*
    template <template <template <class> class, class> class n,
        template <template <class> class, class> class m,
        template <class> class f, class x>
    struct _sub {
        template <class l>
        struct _build {
            using type = pair<church0<f, x>, l>;
        };

        template <class l>
        using build = typename _build<l>::type;

        template <class l>
        struct _iter {
            using type = pair<f<first<l>>, pop_tail<l>>;
        };

        template <class l>
        using iter = typename _iter<l>::type;

        using type = tail<n<iter, m<build, pair<church0<f, x>, marker>>>>;
    };
    */
}

}

#endif
