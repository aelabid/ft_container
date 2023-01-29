#pragma once
# include "containers.hpp"

template < class T, class Alloc = std::allocator<T> > 
class vector
{
    public:
        typedef T                                     value_type;
        typedef std::allocator<value_type>            allocator_type;
        typedef value_type&                           reference;
        typedef const value_type&                     const_reference;
        typedef value_type*                           pointer;
        // typedef const value_type*                     const_pointer;
        // typedef MyIterator<value_type>                iterator;
        // typedef MyConstIterator<value_type>           const_iterator;
        // typedef std::reverse_iterator<iterator>       reverse_iterator;
        // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        // typedef ptrdiff_t                             difference_type;
        typedef size_t                                size_type;

        explicit vector (const allocator_type& alloc = allocator_type())        {
            // std::cout<<"constructor called";
        };
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        {
            this->_my_vector = alloc.allocate(n);
            alloc.construct();
        };

        private:
            pointer _my_vector;
};