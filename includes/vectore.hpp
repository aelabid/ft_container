#pragma once
# include "containers.hpp"

template < class T, class Alloc = std::allocator<T> > class vector
{
    private:
        T *_tab;
        // typedef allocator_type Alloc;
    public:
        vector(const Alloc& alloc = Alloc()):_tab(NULL){
            std::cout<<"constructor called";
        };
};