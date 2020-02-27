#ifndef TEMPLE_PAIR_HPP
#define TEMPLE_PAIR_HPP

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

struct marker {
};

namespace detail {
    template <class l>
    struct _pop_tail;

    template <class l>
    struct _tail;
}

template <class l>
using pop_tail = typename detail::_pop_tail<l>::type;

template <class l>
using tail = typename detail::_tail<l>::type;

namespace detail {
    template <class l>
    struct _pop_tail {
        using type = pair<first<l>, pop_tail<second<l>>>;
    };

    template <class data>
    struct _pop_tail<pair<data, marker>> {
        using type = marker;
    };

    template <class l>
    struct _tail {
        using type = tail<second<l>>;
    };

    template <class data>
    struct _tail<pair<data, marker>> {
        using type = data;
    };
}

}

#endif
