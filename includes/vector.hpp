#pragma once
# include "containers.hpp"

template < class T, class Alloc = std::allocator<T> > 
class vector
{
    public:
    // ------------------------Member Types------------------------ //
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

    // -------------------------------Constructors-------------------------------------//
        // ------------------------ default constructor ------------------------ //
        explicit vector (const allocator_type& alloc = allocator_type())        {
            // std::cout<<"constructor called";
        };

        // ------------------------ fill constructor ------------------------ //
        explicit vector(size_type n, const value_type &val = value_type(),                 const  allocator_type &alloc = allocator_type())
        {
        this->_alloc = alloc;
        this->_size = n;
        this->_vector = this->_alloc.allocate(n);
        for (size_type i = 0; i < n; i++)
            this->_alloc.construct(this->_vector + i, val);
        }

        // ------------------------ range constructor ------------------------ //
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,                 const allocator_type& alloc = allocator_type())
        {
            // cout<<"here";
            this->_alloc = alloc;
            this->_size = last - first;
            this->_vector = this->_alloc.allocate(this->_size);
            for (size_type i = 0; i < this->_size; i++)
                this->_alloc.construct(this->_vector + i, *(first++));
        }



    // ------------------------Operator Overloading------------------------ //
        reference operator[](size_type n) { return this->_vector[n]; }
        const_reference operator[](size_type n) const{ return this->_vector[n]; }

    // ------------------------Private------------------------ //
        private:
            size_type _size;
            allocator_type _alloc;
            pointer _vector;
            size_type _capacity;
};