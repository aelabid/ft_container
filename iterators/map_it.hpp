#pragma once

#include"iterator_traits.hpp"

template<typename T>
class MyBidirectionalIterator
{
    public:
        typedef iterator_traits<T*>::value_type                      value_type;
        typedef iterator_traits<T*>::difference_type                 difference_type;
        typedef iterator_traits<T*>::pointer                         pointer;
        typedef iterator_traits<T*>::reference                       reference;
        typedef iterator_traits<T*>::iterator_category               iterator_category;

        // X b(a);
        MyBidirectionalIterator(){this->_it = NULL;};
        MyBidirectionalIterator(pointer _vec){this->_it = _vec;};
        ~MyBidirectionalIterator(){};
        MyBidirectionalIterator& operator=(const MyBidirectionalIterator& a)
        {
            if (this == &a)
                return *this;
            this->_it = a._it;
            return *this;
        }
        
    private:
        pointer _it;
};