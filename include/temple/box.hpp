#ifndef TEMPLE_BOX_HPP
#define TEMPLE_BOX_HPP

namespace temple {

namespace detail {
    template <template <template<class> class, class> class n>
    struct _nbox {
    };

    template <template <class> class f>
    struct _fbox {
    };
}

template <template <template<class> class, class> class n>
using nbox = detail::_nbox<n>;

template <template <class> class f>
using fbox = detail::_fbox<f>;

}

#endif
