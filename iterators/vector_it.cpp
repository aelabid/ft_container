#pragma once

#include"iterator_traits.hpp"

template<typename T>
class MyRandomAccessIterator
{
public:
    typedef T                               value_type;
    typedef ptrdiff_t                       difference_type;
    typedef T*                              pointer;
    typedef T&                              reference;
    typedef std::random_access_iterator_tag iterator_category;

        // X b(a);
    MyRandomAccessIterator(){this->_it = NULL};
    MyRandomAccessIterator(pointer _vec){this->_it = _vec};
    ~MyRandomAccessIterator();
    // ------------------------Operator Overloading------------------------ //

    private:
        pointer _it;
};
  