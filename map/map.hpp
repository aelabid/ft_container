#pragma once
#include<iostream>
#include<map>
#include"../utils/pair.hpp"
#include"../iterators/vector_it.hpp"
#include"../avl/avl.hpp"

template < class Key,  class T, 
  class Compare = std::less<Key>,
  class Alloc = std::allocator<pair<const Key,T> > > 
class map
{
  public:
    typedef Key                                       key_type;
    typedef T                                         mapped_type;
    typedef pair<const Key, mapped_type>              value_type;
    typedef size_t                                    size_type;
    typedef std::ptrdiff_t                            difference_type;
    typedef Compare                                   key_compare;
    // typedef Comp_val                                  value_compare;
    typedef Alloc                                     allocator_type;
    typedef typename Alloc::reference                 reference;
    typedef typename Alloc::const_reference           const_reference;
    typedef typename Alloc::pointer                   pointer;
    typedef typename Alloc::const_pointer             const_pointer;
    // typedef MyBidirectionalIterator<value_type>       iterator;
    // typedef MyBidirectionalIterator<const value_type> const_iterator;
    // typedef my_rev_it<iterator>                     const_iterator;
    // typedef my_rev_it<const_iterator>                     const_iterator;
    class value_compare : public std::binary_function<value_type, value_type, bool> 
    {
      public:
          bool operator()(const value_type& x, const value_type& y) const
          {
            return (comp(x.first, y.first));
          }
      protected:
          value_compare(key_compare pr) : comp(pr) {}
          key_compare comp;
    };
    public:
      explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
      {
        _alloc = alloc;
        _tree = NULL;
      };
      // template <class InputIterator>
      // map (InputIterator first, InputIterator last,
      //   const key_compare& comp = key_compare(),
      //     const allocator_type& alloc = allocator_type())
      // {
        
      // };
    // map (const map& x)
    // {

    // };
    //  map& operator= (const map& x)
    //  {

    //  };
    // iterator begin()
    // {

    // };
    // const_iterator begin() const
    // {

    // };

    private:
      avlTree<key_type, mapped_type, Alloc> _tree;
      allocator_type  _alloc;
};

// value compare not yet