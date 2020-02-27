#ifndef TEMPLE_TEMPLE_HPP
#define TEMPLE_TEMPLE_HPP

#include <cstdint>

namespace temple {

using int_ = uint32_t;

namespace detail {
    template <int_ k, template <class> class f, class x>
    struct _church;

    template <template <template <class> class, class> class n, template <class> class f, class x>
    struct _inc;

    template <template <template <class> class, class> class n, template <template <class> class, class> class m, template <class> class f, class x>
    struct _add;

    template <template <template <class> class, class> class n, template <template <class> class, class> class m, template <class> class f, class x>
    struct _mul;

    template <template <template <class> class, class> class n, template <template <class> class, class> class p, template <class> class f, class x>
    struct _pow;

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

template <int_ k, template <class> class f, class x>
using church = typename detail::_church<k, f, x>::type;

template <template <template <class> class, class> class n, template <class> class f, class x>
using inc = typename detail::_inc<n, f, x>::type;

template <template <template <class> class, class> class n, template <template <class> class, class> class m, template <class> class f, class x>
using add = typename detail::_add<n, m, f, x>::type;

template <template <template <class> class, class> class n, template <template <class> class, class> class m, template <class> class f, class x>
using mul = typename detail::_mul<n, m, f, x>::type;

template <template <template <class> class, class> class n, template <template <class> class, class> class p, template <class> class f, class x>
using pow = typename detail::_pow<n, p, f, x>::type;

template <template <template <template <class> class, class> class, template <class> class, class> class unary,
    template <template <class> class, class> class n>
using apply_unary = detail::_apply_unary<unary, n>;

template <template <template <template <class> class, class> class, template <template <class> class, class> class, template <class> class, class> class binary,
    template <template <class> class, class> class m,
    template <template <class> class, class> class n>
using apply_binary = detail::_apply_binary<binary, m, n>;

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
using church8 = pow<church2, church3, f, x>;

namespace detail {
    template <int_ k, template <class> class f, class x>
    struct _church {
        using type = f<church<k - 1, f, x>>;
    };

    template <template <class> class f, class x>
    struct _church<0, f, x> {
        using type = x;
    };

    template <template <template <class> class, class> class n, template <class> class f, class x>
    struct _inc {
        using type = f<n<f, x>>;
    };

    template <template <template <class> class, class> class n, template <template <class> class, class> class m, template <class> class f, class x>
    struct _add {
        using type = m<f, n<f, x>>;
    };

    template <template <template <class> class, class> class n, template <template <class> class, class> class m, template <class> class f, class x>
    struct _mul {
        template <class y>
        struct _mfold {
            using type = m<f, y>;
        };

        template <class y>
        using mfold = typename _mfold<y>::type;

        using type = n<mfold, x>;
    };

    template <template <template <class> class, class> class n, template <template <class> class, class> class p, template <class> class f, class x>
    struct _pow {
    };
}

}

#endif
