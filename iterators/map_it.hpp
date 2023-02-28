#pragma once

#include"iterator_traits.hpp"
#include"../avl/avl.hpp"
#include"../utils/pair.hpp"
template<class V, class T>
class MyBidirectionalIterator
{
    public:
        typedef typename iterator_traits<T*>::value_type                      value_type;
        typedef typename iterator_traits<T*>::difference_type                 difference_type;
        typedef typename iterator_traits<T*>::pointer                         pointer;
        typedef typename iterator_traits<T*>::reference                       reference;
        typedef std::bidirectional_iterator_tag                      iterator_category;
        // X b(a);
        MyBidirectionalIterator(){}
        MyBidirectionalIterator(V tree, value_type _vec)
        {
            _tree = tree;
            _it = _vec;
            node = _vec->node;
        }
        ~MyBidirectionalIterator(){}
        MyBidirectionalIterator& operator=(const MyBidirectionalIterator& a)
        {
            if (this == &a)
                return *this;
            this->_it = a;
            this->node = a.node;
            return *this;
        }
        bool operator==(const MyBidirectionalIterator& a) const { return a._it == _it; };
        bool operator!=(const MyBidirectionalIterator& a) const { return a._it == _it; };
        const ft::pair<int, int>& operator*() const{ return node; };
        const ft::pair<int, int>* operator->() const { return &node; };
        MyBidirectionalIterator &operator--()
        {
            // _tree.get_root(this->_it);
            std::cout<<"here"<<_it->parent->node.first;
            return *this;
        }
    private:
        value_type _it;
        V   _tree;
        // avlTree<Key, Val, Compare, Alloc> _tree;
        ft::pair<int, int> node;
};