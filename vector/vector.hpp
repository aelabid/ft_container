#pragma once
#include"../iterators/vector_it.hpp"
#include <stdexcept>
#include<iostream>
#include<climits>
#include"../utils/equal.hpp"
#include"../utils/is_integral.hpp"
#include"../utils/enable_if.hpp"
#include"../utils/lexicographical_compare.hpp"
namespace ft {

template < typename T, class Alloc = std::allocator<T> > 
class vector
{
    public:
    // ------------------------Member Types------------------------ //
        typedef T                                           value_type;
        typedef std::allocator<value_type>                  allocator_type;
        typedef value_type&                                 reference;
        typedef const value_type&                           const_reference;
        typedef value_type*                                 pointer;
        typedef const value_type*                        const_pointer;
        typedef ft::MyRandomAccessIterator<value_type>          iterator;
        typedef ft::MyRandomAccessIterator<const value_type>    const_iterator;
        typedef ft::my_rev_it<iterator>                       reverse_iterator;
        typedef ft::my_rev_it<const iterator>                 const_reverse_iterator;
        typedef ptrdiff_t                                difference_type;
        typedef size_t                                      size_type;

    // -------------------------------Constructors-------------------------------------//
        // ------------------------ default constructor ------------------------ //
        explicit vector (const allocator_type& alloc = allocator_type())        {
            // std::cout<<"constructor called";
          this->_alloc = alloc;
          this->_size = 0;
          this->_capacity = 0;
          this->_vector = _alloc.allocate(0);
        };

        // ------------------------ fill constructor ------------------------ //
        explicit vector(size_type n, const value_type &val = value_type(),                 const  allocator_type &alloc = allocator_type())
        {
            this->_alloc = alloc;
            this->_size = n;
            this->_capacity = n;
            this->_vector = this->_alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                this->_alloc.construct(&this->_vector[i], val);
        }

        // ------------------------ range constructor ------------------------ //
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,            const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
        {
            this->_alloc = alloc;
            this->_size = last - first;
            this->_capacity = _size;
            this->_vector = this->_alloc.allocate(this->_capacity);
            for (size_type i = 0; i < this->_size; i++)
            {
              this->_alloc.construct(&this->_vector[i], *first);
              first++;
            }
        }
        // ------------------------ copy constructor ------------------------ //
        vector (const vector& x)
        {
            this->_capacity = x._capacity;
            this->_alloc = x._alloc;
            this->_size = x._size;
            this->_vector = this->_alloc.allocate(this->_capacity);
            for(size_type i = 0; i < this->_size; i++)
                this->_alloc.construct(&this->_vector[i], x._vector[i]);
        }
        // ------------------------ Destructor ------------------------ //
        ~vector ()
        {
            if(!this->_size)
                return ;
            for(size_type i = 0; i < this->_size; i++)
                this->_alloc.destroy(&this->_vector[i]);
            this->_alloc.deallocate(this->_vector, this->_capacity);
        }
    // ------------------------Operator Overloading------------------------ //
        vector& operator= (const vector& x)
        {
            if (this == &x)
                return *this;
            for(size_type i = 0; i < this->_size; i++)
                this->_alloc.destroy(&this->_vector[i]);
            this->_alloc.deallocate(this->_vector, this->_capacity);
            this->_vector = this->_alloc.allocate(x._capacity);
            this->_capacity = x._capacity;
            this->_size = x._size;
            for (size_type i = 0; i < this->_size; i++)
                this->_alloc.construct(&this->_vector[i], x._vector[i]);
            return(*this);
        }
        

    // ------------------------ Iterators ------------------------ //
        iterator begin()
        {
            return (iterator(this->_vector));
        }
        const_iterator begin() const
        {
            return (const_iterator(this->_vector));
        }
        iterator end()
        {
            return (iterator(this->_vector + _size));
        }
        const_iterator end() const
        {
            return (const_iterator(this->_vector + _size));
        }
        reverse_iterator rbegin()
        {
            return (reverse_iterator(this->_vector + _size));
        }
        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(this->_vector + _size));
        }
        reverse_iterator rend()
        {
            return (reverse_iterator(this->_vector));
        }
        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(this->_vector));
        }
    // ------------------------Capacity------------------------ //
    size_type size() const
    {
        return _size;
    }
    size_type max_size() const
    {
        return (this->_alloc.max_size());
    };
    void resize (size_type n, value_type val = value_type())
    {
        if(n < _size)
        {
            for (size_t i = n; i < _size; i++)
                _alloc.destroy(&_vector[i]);
        }
        else if (n > _capacity)
        {
            value_type *tmp = _alloc.allocate(n);
            for (int i=0; i<_size; i++)
            {
                _alloc.construct(&tmp[i], _vector[i]);
                _alloc.destroy(&_vector[i]);
            }
            _alloc.deallocate(_vector, _capacity);
            _vector = tmp;
            _size = n;
            _capacity = (_size == 0) ? 1 : (_size-1) * 2;
        }
        else if (n>_size)
        {
            for (size_t i = _size; i < n; i++)
                _alloc.construct(&_vector[i], val);
        }
        _size = n;
    };
    size_type capacity() const
    {
        return _capacity;
    }
    bool empty() const
    {
        return (_size == 0);
    }
    void reserve (size_type n)
    {
        if (n > _capacity)
        {
            value_type *tmp = _alloc.allocate(n);
            for (size_type i=0; i<_size; i++)
            {
                _alloc.construct(&tmp[i], _vector[i]);
                _alloc.destroy(&_vector[i]);
            }
            for (size_type i=_size; i<n; i++)
                _alloc.construct(&tmp[i], value_type());
            _alloc.deallocate(_vector, _capacity);
            _vector = tmp;
            _capacity = n;
        }
    }
    // ------------------------ Element access ------------------------ //
        reference operator[](size_type n) 
        { 
            return this->_vector[n]; 
        }
        const_reference operator[](size_type n) const
        { 
            return this->_vector[n];
        }
        reference at (size_type n)
        {
            if(n>_size)
                throw std::out_of_range("");
            return (this->_vector[n]);
        };
        const_reference at (size_type n) const
        {
            if(n>_size)
                throw std::out_of_range("");
            return(this->_vector[n]);
        };
        reference front()
        {
            return _vector[0];
        };
        const_reference front() const
        {
            return _vector[0];

        };
        reference back()
        {
            return _vector[_size - 1];
        };
        const_reference back() const
        {
            return _vector[_size - 1];

        };
    // ------------------------Modifiers------------------------ //
    template <class InputIterator>
    void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
    {
        size_type size = last - first;
        if (size >= UINT_MAX)
            throw std::length_error("");
        reserve(size);
        size_type i = 0;
        while (i<size)
        {
            _alloc.destroy(&_vector[i]);
            _alloc.construct(&_vector[i], *first);
            first++;
            i++;
        }
        _size = size;
    };
    void assign (size_type n, const value_type& val)
    {
        reserve(n);
        size_type i =0;
        while (i<n)
        {
            _alloc.destroy(&_vector[i]);
            _alloc.construct(&_vector[i], val);
            i++;
        }
        _size = n;
    };
    void push_back (const value_type& val)
    {
        size_type tmp = _size;
        if(_size + 1 > _capacity)
        {
            reserve(_size + 1);
            _alloc.destroy(&_vector[tmp]);
            _capacity = (tmp==0) ? 1 : tmp*2;
        }
        _alloc.construct(&_vector[tmp], val);
        _size = tmp + 1;
    };
    void pop_back()
    {
        if(_size)
        {
            _alloc.destroy(&_vector[_size]);
            _size --;
        }
    };
    iterator insert (iterator position, const value_type& val)
    {
        size_type m, t = _size;
        size_type dst = position - begin();
        if(dst <= _size)
            m = _size+1;
        else
            m=dst+1; 
        pointer temp = _alloc.allocate(m);
        for (int i=0; i<_size; i++)
        {
            _alloc.construct(&temp[i], _vector[i]);
            _alloc.destroy(&_vector[i]);
        }
        _alloc.deallocate(_vector, _capacity);
        _vector = temp;
        _size = (_size>dst)?_size+1 : dst+1;
        if(m>_capacity)
        {
            if(t==0)
                _capacity = 1;
            else
            {
                _capacity = t*2;
            }
        }
        // _capacity = (t == 0) ? 1 : t * 2;
        if (dst >= UINT_MAX)
            throw std::length_error("");
        pointer tmp = _alloc.allocate(dst);
        value_type tm;
        size_type i;
        for(i = _size; i > dst; i--)
            _vector[i] = _vector[i - 1];
        _alloc.destroy(&_vector[i]);
        _alloc.construct(&_vector[i], val);
        return  iterator(_vector + dst);
    };

    void insert (iterator position, size_type n, const value_type& val)
    {
        size_type dst = position - begin();
        if(dst >= _size)
            _capacity = _size + n;
        for (size_type i =0; i < n; i++)
        {
            position = insert(position, val);
        }
    };
    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
    {
        while(first != last)
        {
            position = insert(position, *first);
            first++;
        }
    };
    iterator erase (iterator position)
    {
        size_type dst = position - begin();
        if (dst >= UINT_MAX)
            throw std::length_error("");
        if(dst>_size)
            return NULL;
        _size--;
        for(size_type i = dst; i<_size; i++)
        {
            _alloc.destroy(&_vector[i]);
            _alloc.construct(&_vector[i], _vector[i+1]);
        }
        return iterator(_vector + dst);
    };
    iterator erase (iterator first, iterator last)
    {
        iterator position;
        size_type dst = last - first;
        while(dst>0)
        {
            first++;
            position = erase(--first);
            dst--;
        }
        return iterator(position);
    };
    void swap (vector& x)
    {
        size_type       tmp_size = x._size;
        allocator_type  tmp_alloc = x._alloc;
        pointer         tmp_vector = x._vector;
        size_type       tmp_capacity = x._capacity;
        x._size = _size;
        x._alloc = _alloc;
        x._vector = _vector;
        x._capacity = _capacity;

        _size = tmp_size;
        _alloc = tmp_alloc;
        _vector = tmp_vector;
        _capacity = tmp_capacity;
    };
    void clear()
    {
        while(!empty())
            pop_back();
    };
    // ------------------------Allocator------------------------ //
    allocator_type get_allocator() const
    {
        return _alloc;
    };
    // ------------------------Private------------------------ //
        private:
            size_type       _size;
            allocator_type  _alloc;
            pointer         _vector;
            size_type       _capacity;
};

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return((lhs.size() == rhs.size()) && equal(lhs.begin(), lhs.end(), rhs.begin()));
};
template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return(!(lhs == rhs));
};
template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};
template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin())
                || ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};
template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());

};
template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())
            || ft::equal(lhs.begin(), lhs.end(), rhs.begin());;
};
}