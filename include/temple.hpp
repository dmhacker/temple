#ifndef TEMPLE_TEMPLE_HPP
#define TEMPLE_TEMPLE_HPP

namespace temple {

namespace detail {
    template <template <class> class f, class x>
    struct _church0;

    template <template <class> class f, class x>
    struct _church1;

    template <template <class> class f, class x>
    struct _church2;

    template <template <template <class> class, class> class n, template <class> class f, class x>
    struct _inc;

    template <template <template <class> class, class> class m, template <template <class> class, class> class n, template <class> class f, class x>
    struct _add;

    template <template <template <template <class> class, class> class, template <class> class, class> class unary,
        template <template <class> class, class> class n>
    struct _apply_unary {
        template <template <class> class f, class x>
        using church = unary<n, f, x>;
    };

    template <template <template <template <class> class, class> class, template <template <class> class, class> class, template <class> class, class> class binary,
        template <template <class> class, class> class m,
        template <template <class> class, class> class n>
    struct _apply_binary {
        template <template <class> class f, class x>
        using church = binary<m, n, f, x>;
    };
}

template <template <class> class f, class x>
using church0 = typename detail::_church0<f, x>::type;

template <template <class> class f, class x>
using church1 = typename detail::_church1<f, x>::type;

template <template <class> class f, class x>
using church2 = typename detail::_church2<f, x>::type;

template <template <template <class> class, class> class n, template <class> class f, class x>
using inc = typename detail::_inc<n, f, x>::type;

template <template <template <class> class, class> class m, template <template <class> class, class> class n, template <class> class f, class x>
using add = typename detail::_add<m, n, f, x>::type;

template <template <template <template <class> class, class> class, template <class> class, class> class unary,
    template <template <class> class, class> class n>
using apply_unary = detail::_apply_unary<unary, n>;

template <template <template <template <class> class, class> class, template <template <class> class, class> class, template <class> class, class> class binary,
    template <template <class> class, class> class m,
    template <template <class> class, class> class n>
using apply_binary = detail::_apply_binary<binary, m, n>;

template <template <class> class f, class x>
using church3 = typename apply_unary<inc, church2>::church<f, x>::type;

template <template <class> class f, class x>
using church4 = typename apply_binary<add, church2, church2>::church<f, x>::type;

template <template <class> class f, class x>
using church5 = typename apply_binary<add, church3, church2>::church<f, x>::type;

namespace detail {
    template <template <class> class f, class x>
    struct _church0 {
        using type = x;
    };

    template <template <class> class f, class x>
    struct _church1 {
        using type = f<x>;
    };

    template <template <class> class f, class x>
    struct _church2 {
        using type = f<f<x>>;
    };

    template <template <template <class> class, class> class n, template <class> class f, class x>
    struct _inc {
        using type = f<n<f, x>>;
    };

    template <template <template <class> class, class> class m, template <template <class> class, class> class n, template <class> class f, class x>
    struct _add {
        using type = m<f, n<f, x>>;
    };
}

}

#endif
