#ifndef TEMPLE_FIXPOINT_HPP
#define TEMPLE_FIXPOINT_HPP

#include "box.hpp"

namespace temple {

namespace detail {
    template <class step>
    struct _fix;
}

template <class step>
using fix = typename detail::_fix<step>::type;

namespace detail {
    template <class step>
    struct _fix {
    };

    template <template <class, class> class step>
    struct _fix<bbox<step>> {

    };
}

}

#endif
