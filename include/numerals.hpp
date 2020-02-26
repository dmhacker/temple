#ifndef TEMPLE_TEMPLE_HPP
#define TEMPLE_TEMPLE_HPP

#include <cstdint>

namespace temple {

using int_ = uint32_t;

namespace detail {
    template <template <class> class f, class x>
    struct _church0;

    template <template <class> class f, class x>
    struct _church1;

    template <int_ k, template <class> class f, class x>
    struct _churchk;

    template <template <template <class> class, class> class n, template <class> class f, class x>
    struct _inc;

    template <template <template <class> class, class> class m, template <template <class> class, class> class n, template <class> class f, class x>
    struct _add;

    template <template <template <class> class, class> class m, template <template <class> class, class> class n, template <class> class f, class x>
    struct _mul;

    template <template <template <template <class> class, class> class, template <class> class, class> class unary,
        template <template <class> class, class> class n>
    struct _apply_unary {
        template <template <class> class f, class x>
        using type = unary<n, f, x>;
    };

    template <template <template <template <class> class, class> class, template <template <class> class, class> class, template <class> class, class> class binary,
        template <template <class> class, class> class m,
        template <template <class> class, class> class n>
    struct _apply_binary {
        template <template <class> class f, class x>
        using type = binary<m, n, f, x>;
    };
}

template <template <class> class f, class x>
using church0 = typename detail::_church0<f, x>::type;

template <template <class> class f, class x>
using church1 = typename detail::_church1<f, x>::type;

template <int_ k, template <class> class f, class x>
using churchk = typename detail::_churchk<k, f, x>::type;

template <template <template <class> class, class> class n, template <class> class f, class x>
using inc = typename detail::_inc<n, f, x>::type;

template <template <template <class> class, class> class m, template <template <class> class, class> class n, template <class> class f, class x>
using add = typename detail::_add<m, n, f, x>::type;

template <template <template <class> class, class> class m, template <template <class> class, class> class n, template <class> class f, class x>
using mul = typename detail::_mul<m, n, f, x>::type;

template <template <template <template <class> class, class> class, template <class> class, class> class unary,
    template <template <class> class, class> class n>
using apply_unary = detail::_apply_unary<unary, n>;

template <template <template <template <class> class, class> class, template <template <class> class, class> class, template <class> class, class> class binary,
    template <template <class> class, class> class m,
    template <template <class> class, class> class n>
using apply_binary = detail::_apply_binary<binary, m, n>;

template <template <class> class f, class x>
using church2 = typename apply_unary<inc, church1>::type<f, x>::type;

template <template <class> class f, class x>
using church3 = typename apply_unary<inc, church2>::type<f, x>::type;

template <template <class> class f, class x>
using church4 = typename apply_binary<add, church2, church2>::type<f, x>::type;

template <template <class> class f, class x>
using church5 = typename apply_binary<add, church3, church2>::type<f, x>::type;

template <template <class> class f, class x>
using church6 = typename apply_binary<mul, church3, church2>::type<f, x>::type;

template <template <class> class f, class x>
using church7 = typename apply_unary<inc, church6>::type<f, x>::type;

namespace detail {
    template <template <class> class f, class x>
    struct _church0 {
        using type = x;
    };

    template <template <class> class f, class x>
    struct _church1 {
        using type = f<x>;
    };

    template <int_ k, template <class> class f, class x>
    struct _churchk {
        using type = f<typename _churchk<k - 1, f, x>::type>;   
    };

    template <template <class> class f, class x>
    struct _churchk<0, f, x> {
        using type = x;
    };

    template <template <template <class> class, class> class n, template <class> class f, class x>
    struct _inc {
        using type = f<n<f, x>>;
    };

    template <template <template <class> class, class> class m, template <template <class> class, class> class n, template <class> class f, class x>
    struct _add {
        using type = m<f, n<f, x>>;
    };

    template <template <template <class> class, class> class m, template <template <class> class, class> class n, template <class> class f, class x>
    struct _mul {
        template <class y>
        struct _nfold {
            using type = n<f, y>;
        };

        template <class y>
        using nfold = typename _nfold<y>::type;

        using type = m<nfold, x>;
    };
}

}

#endif
