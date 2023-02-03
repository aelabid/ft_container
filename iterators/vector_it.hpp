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
    MyRandomAccessIterator(){this->_it = NULL;};
    MyRandomAccessIterator(pointer _vec){this->_it = _vec;};
    // ~MyRandomAccessIterator();
    // ------------------------Operator Overloading------------------------ //
    MyRandomAccessIterator& operator=(const MyRandomAccessIterator& a)
    {
        if (this == &a)
            return *this;
        this->_it = a._it;
        return *this;
    }
    bool operator==(MyRandomAccessIterator const &a)
    {
        return a._it == _it;
    }
    bool operator!=(MyRandomAccessIterator const &a)
    {
        return a._it != _it;
    }
    T& operator*() const
    {
        return *_it;
    }
    pointer operator->() const
    {
        return _it;
    }
    MyRandomAccessIterator &operator++()
    {
        _it++;
        return *this;
    }
    MyRandomAccessIterator operator++(int)
    {
        MyRandomAccessIterator tmp(_it);
        _it++;
        return tmp;
    }
    MyRandomAccessIterator &operator--()
    {
        _it--;
        return *this;
    }
    MyRandomAccessIterator operator--(int)
    {
        MyRandomAccessIterator tmp(_it);
        _it--;
        return tmp;
    }
    MyRandomAccessIterator operator+(difference_type a) const
    {
        return _it + a;
    }
    MyRandomAccessIterator operator-(difference_type a) const
    {
        return _it - a;
    }
    private:
        pointer _it;
};
