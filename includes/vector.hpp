#pragma once
# include "containers.hpp"
#include"../iterators/vector_it.hpp"
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
        typedef MyRandomAccessIterator<value_type>                iterator;
        // typedef MyConstIterator<value_type>           const_iterator;
        // typedef std::reverse_iterator<iterator>       reverse_iterator;
        // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        // typedef ptrdiff_t                             difference_type;
        typedef size_t                                size_type;

    // -------------------------------Constructors-------------------------------------//
        // ------------------------ default constructor ------------------------ //
        explicit vector (const allocator_type& alloc = allocator_type())        {
            // std::cout<<"constructor called";
          this->_alloc = alloc;
          this->_size = 0;
          this->_capacity = 0;
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
        template <typename InputIterator>
        vector (InputIterator first, InputIterator last,                 const allocator_type& alloc = allocator_type(), typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
        {
            this->_alloc = alloc;
            this->_size = last - first;
            this->_vector = this->_alloc.allocate(this->_size);
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
            this->_vector = this->_alloc.allocate(this->_size);
            for(size_type i = 0; i < this->_size; i++)
                this->_alloc.construct(&this->_vector[i], x._vector[i]);
        }
        // ------------------------ Destructor ------------------------ //
        ~vector ()
        {
            if(!this->_vector)
                return ;
            for(size_type i = 0; i < this->_size; i++)
                this->_alloc.destroy(&this->_vector[i]);
            this->_alloc.deallocate(this->_vector, this->_size);
        }
    // ------------------------Operator Overloading------------------------ //
        vector& operator= (const vector& x)
        {
            // Guard self assignment
            if (this == &x)
                return *this;
            this->_capacity = x._capacity;
            this->_size = x._size;
            for(size_type i = 0; i < this->_size; i++)
                this->_alloc.destroy(&this->_vector[i]);
            this->_alloc.deallocate(this->_vector, this->_size);
            this->_alloc.allocate(x._size);
            for (size_type i = 0; i < this->_size; i++)
                this->_alloc.construct(&this->_vector[i], x._vector[i]);
        }
        reference operator[](size_type n) { return this->_vector[n]; }
        const_reference operator[](size_type n) const{ return this->_vector[n]; }

    // ------------------------Operator Overloading------------------------ //
        iterator begin()
        {
            return (iterator(this->_vector));
        }
    
    // ------------------------Private------------------------ //
        private:
            size_type _size;
            allocator_type _alloc;
            pointer _vector;
            size_type _capacity;
};