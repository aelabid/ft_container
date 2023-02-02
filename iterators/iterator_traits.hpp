#pragma once
#include<cstddef>

template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef Category iterator_category;
        typedef Type value_type;
        typedef Distance difference_type;
        typedef Distance distance_type;
        typedef Pointer pointer;
        typedef Reference reference;
};

template <class Iter>
    class iterator_traits {
        public:
            typedef typename Iter::value_type            value_type;
            typedef typename Iter::difference_type       difference_type;
            typedef typename Iter::iterator_category     iterator_category;
            typedef typename Iter::pointer               pointer;
            typedef typename Iter::reference             reference;
    };
    
    
    
template <class T>
    class iterator_traits<T*>
    {
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    

template <class T>
    class iterator_traits<const T*>
    {
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
