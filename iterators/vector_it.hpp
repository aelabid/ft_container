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
    ~MyRandomAccessIterator(){};
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
        return MyRandomAccessIterator(_it - a);
    }
    difference_type operator-(MyRandomAccessIterator const &a) const
    {
        return _it - a._it;
    }
    bool operator>(const MyRandomAccessIterator &a) const
    {
        return _it > a._it;
    }
    bool operator<(const MyRandomAccessIterator &a) const
    {
        return _it < a._it;
    }
    bool operator<=(const MyRandomAccessIterator &a) const
    {
        return _it <= a._it;
    }
    bool operator>=(const MyRandomAccessIterator &a) const
    {
        return _it >= a._it;
    }
    void operator+=(difference_type a)
    {
        _it += a;
    }
    void operator-=(difference_type a)
    {
        _it -= a;
    }
    reference operator[](difference_type a) const
    {
        return *(_it + a);
    }
    private:
        pointer _it;
};

template<class T>
class my_rev_it
{
public:
    typedef T                                               iterator_type;
    typedef typename iterator_traits<T>::iterator_category iterator_category;
    typedef typename iterator_traits<T>::value_type        value_type;
    typedef typename iterator_traits<T>::difference_type   difference_type;
    typedef typename iterator_traits<T>::pointer            pointer;
    typedef typename iterator_traits<T>::reference         reference;

    my_rev_it(){};
    template <class Iter> 
    my_rev_it (const my_rev_it<Iter>& rev_it)
    {
        *this = rev_it;
    };
    explicit my_rev_it (iterator_type it){ _crt = it; };
    ~my_rev_it(){};

    iterator_type base() const {
        return _crt;
    }
    // ------------------------Operator Overloading------------------------ //
    T& operator*() const
    {
        return *(_crt - 1);
    }
    pointer operator->() const
    {
        return &(operator*());
    }
    my_rev_it &operator++()
    {
        _crt--;
        return *this;
    }
    my_rev_it operator++(int)
    {
        my_rev_it tmp(_crt);
        _crt--;
        return tmp;
    }
    my_rev_it &operator--()
    {
        _crt++;
        return *this;
    }
    my_rev_it operator--(int)
    {
        my_rev_it tmp(_crt);
        _crt--;
        return tmp;
    }
    my_rev_it operator+(difference_type a) const
    {
        return my_rev_it(_crt - a);
    }
    my_rev_it operator-(difference_type a) const
    {
        return my_rev_it(_crt + a);
    }
    void operator+=(difference_type a)
    {
        _crt -= a;
    }
    void operator-=(difference_type a)
    {
        _crt += a;
    }
    reference operator[](difference_type a) const
    {
        return base()[-a-1];
    }
    private:
        iterator_type       _crt;
};

template <class Iterator>  
bool operator== (const my_rev_it<Iterator>& lhs, const my_rev_it<Iterator>& rhs)
{
    return lhs.base() == rhs.base();
};

template <class Iterator>
bool operator!= (const my_rev_it<Iterator>& lhs,                   const my_rev_it<Iterator>& rhs)
{
    return lhs.base() != rhs.base();
};

template <class Iterator>
bool operator<  (const my_rev_it<Iterator>& lhs,                   const my_rev_it<Iterator>& rhs)
{
    return lhs.base() < rhs.base();
};

template <class Iterator>
bool operator<=  (const my_rev_it<Iterator>& lhs,                   const my_rev_it<Iterator>& rhs)
{
    return lhs.base() <= rhs.base();
};

template <class Iterator>
bool operator>  (const my_rev_it<Iterator>& lhs,                   const my_rev_it<Iterator>& rhs)
{
    return lhs.base() > rhs.base();
};

template <class Iterator>
bool operator>=  (const my_rev_it<Iterator>& lhs,                   const my_rev_it<Iterator>& rhs)
{
    return lhs.base() >= rhs.base();
};

template <class Iterator>
my_rev_it<Iterator> operator+ (typename my_rev_it<Iterator>::difference_type n,             const my_rev_it<Iterator>& rev_it)
{
    return my_rev_it<Iterator>(rev_it - n);
};


template <class Iterator>  
typename my_rev_it<Iterator>::difference_type operator- (    const my_rev_it<Iterator>& lhs,    const my_rev_it<Iterator>& rhs)
{
    return rhs - lhs;
};

//operator n + it