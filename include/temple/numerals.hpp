#ifndef TEMPLE_NUMERALS_HPP
#define TEMPLE_NUMERALS_HPP

#include <cstdint>

#include "pair.hpp"

namespace temple {

using int_ = uint32_t;

namespace detail {
    template <int_ k, template <class> class f, class x>
    struct _church;

    template <template <template <class> class, class> class n,
        template <class> class f, class x>
    struct _inc;

    template <template <template <class> class, class> class n,
        template <class> class f, class x>
    struct _dec;

    template <template <template <class> class, class> class n,
        template <template <class> class, class> class m,
        template <class> class f, class x>
    struct _add;

    template <template <template <class> class, class> class n,
        template <template <class> class, class> class m,
        template <class> class f, class x>
    struct _mul;

    template <template <template <class> class, class> class n,
        template <template <class> class, class> class m,
        template <class> class f, class x>
    struct _sub;
}

template <int_ k, template <class> class f, class x>
using church = typename detail::_church<k, f, x>::type;

template <template <template <class> class, class> class n, template <class> class f, class x>
using inc = typename detail::_inc<n, f, x>::type;

template <template <template <class> class, class> class n, template <class> class f, class x>
using dec = typename detail::_dec<n, f, x>::type;

template <template <template <class> class, class> class n, template <template <class> class, class> class m, template <class> class f, class x>
using add = typename detail::_add<n, m, f, x>::type;

template <template <template <class> class, class> class n, template <template <class> class, class> class m, template <class> class f, class x>
using mul = typename detail::_mul<n, m, f, x>::type;

template <template <template <class> class, class> class n, template <template <class> class, class> class m, template <class> class f, class x>
using sub = typename detail::_sub<n, m, f, x>::type;

template <template <class> class f, class x>
using church0 = church<0, f, x>;

template <template <class> class f, class x>
using church1 = church<1, f, x>;

template <template <class> class f, class x>
using church2 = inc<church1, f, x>;

template <template <class> class f, class x>
using church3 = inc<church2, f, x>;

template <template <class> class f, class x>
using church4 = add<church2, church2, f, x>;

template <template <class> class f, class x>
using church5 = add<church3, church2, f, x>;

template <template <class> class f, class x>
using church6 = mul<church3, church2, f, x>;

template <template <class> class f, class x>
using church7 = inc<church6, f, x>;

template <template <class> class f, class x>
using church8 = mul<church4, church2, f, x>;

namespace detail {
    template <int_ k, template <class> class f, class x>
    struct _church {
        using type = f<church<k - 1, f, x>>;
    };

    template <template <class> class f, class x>
    struct _church<0, f, x> {
        using type = x;
    };

    template <template <template <class> class, class> class n,
        template <class> class f, class x>
    struct _inc {
        using type = f<n<f, x>>;
    };

    template <template <template <class> class, class> class n,
        template <class> class f, class x>
    struct _dec {
        template <class p>
        struct _iter {
            using type = pair<second<p>, f<second<p>>>;
        };

        template <class y>
        using iter = typename _iter<y>::type;

        using type = first<n<iter, pair<church0<f, x>, church0<f, x>>>>;
    };

    template <template <template <class> class, class> class n,
        template <template <class> class, class> class m,
        template <class> class f, class x>
    struct _add {
        using type = m<f, n<f, x>>;
    };

    template <template <template <class> class, class> class n,
        template <template <class> class, class> class m,
        template <class> class f, class x>
    struct _mul {
        template <class y>
        struct _mfold {
            using type = m<f, y>;
        };

        template <class y>
        using mfold = typename _mfold<y>::type;

        using type = n<mfold, x>;
    };

    template <template <template <class> class, class> class n,
        template <template <class> class, class> class m,
        template <class> class f, class x>
    struct _sub {
        template <class l>
        struct _pop_tail {
            using type = pair<first<l>, typename _pop_tail<second<l>>::type>;
        };

        template <class data>
        struct _pop_tail<pair<data, char>> {
            using type = char;
        };

        template <class l>
        using pop_tail = typename _pop_tail<l>::type;

        template <class l>
        struct _tail {
            using type = typename _tail<second<l>>::type;
        };

        template <class data>
        struct _tail<pair<data, char>> {
            using type = data;
        };

        template <class l>
        using tail = typename _tail<l>::type;

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

        using base = m<build, pair<church0<f, x>, char>>;
        using type = tail<n<iter, base>>;
    };
}

}

#endif
