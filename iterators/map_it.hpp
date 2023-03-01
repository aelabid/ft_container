#pragma once

#include"iterator_traits.hpp"
#include"../avl/avl.hpp"
#include"../utils/pair.hpp"
template<class V, class T, class Key, class Val>
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
            this->_it = a._it;
            this->node = a.node;
            return *this;
        }
        bool operator==(const MyBidirectionalIterator& a) const { return node == a.node; };
        bool operator!=(const MyBidirectionalIterator& a) const { return node != a.node; };
        const ft::pair<Key, Val>& operator*() const{ return node; };
        const ft::pair<Key, Val>* operator->() const { return &node; };
        MyBidirectionalIterator &operator--()
        {
            T   prev = _tree.get_prev_key(_tree._tr, node.first);
            node.first = prev->node.first;
            node.second = prev->node.second;
            return *this;
        }
        MyBidirectionalIterator &operator++()
        {
            T   next = _tree.get_next(_tree._tr, node.first);
            node.first = next->node.first;
            node.second = next->node.second;
            return *this;
        }
        MyBidirectionalIterator operator--(int)
        {
            MyBidirectionalIterator tmp(*this);
            --(*this);
            return tmp;
        }
        MyBidirectionalIterator operator++(int)
        {
            MyBidirectionalIterator tmp(*this);
            ++(*this);
            return tmp;
        }
    private:
        value_type _it;
        V   _tree;
        ft::pair<Key, Val> node;
};

// template<class V, class T, class Key, class Val>
// class reverse_iterator_m
// {
//     public:
//         typedef typename iterator_traits<T*>::value_type                      value_type;
//         typedef typename iterator_traits<T*>::difference_type                 difference_type;
//         typedef typename iterator_traits<T*>::pointer                         pointer;
//         typedef typename iterator_traits<T*>::reference                       reference;
//         typedef std::bidirectional_iterator_tag                      iterator_category;
//         // X b(a);
//         reverse_iterator_m(){}
//         reverse_iterator_m(V tree, value_type _vec)
//         {
//             _tree = tree;
//             _it = _vec;
//             node = _vec->node;
//         }
//         ~reverse_iterator_m(){}
//         reverse_iterator_m& operator=(const reverse_iterator_m& a)
//         {
//             if (this == &a)
//                 return *this;
//             this->_it = a._it;
//             this->node = a.node;
//             return *this;
//         }
//         bool operator==(const reverse_iterator_m& a) const { return node == a.node; };
//         bool operator!=(const reverse_iterator_m& a) const { return node != a.node; };
//         const ft::pair<Key, Val>& operator*() const{ return node; };
//         const ft::pair<Key, Val>* operator->() const { return &node; };
//         reverse_iterator_m &operator--()
//         {
//             T   prev = _tree.get_next(_tree._tr, node.first);
//             node.first = prev->node.first;
//             node.second = prev->node.second;
//             return *this;
//         }
//         reverse_iterator_m &operator++()
//         {
//             T   next = _tree.get_prev_key(_tree._tr, node.first);
//             node.first = next->node.first;
//             node.second = next->node.second;
//             return *this;
//         }
//         reverse_iterator_m operator--(int)
//         {
//             reverse_iterator_m tmp(*this);
//             ++(*this);
//             return tmp;
//         }
//         reverse_iterator_m operator++(int)
//         {
//             reverse_iterator_m tmp(*this);
//             --(*this);
//             return tmp;
//         }
//     private:
//         value_type _it;
//         V   _tree;
//         ft::pair<Key, Val> node;
// };