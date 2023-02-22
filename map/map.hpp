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
  private:
    class Comp_val
    {
      protected:
          Compare comp;
      public:
        Comp_val()
        {
          comp = Compare();
        }
        bool operator()(const pair<const Key, T> &lhs, const pair<const Key, T> &rhs) const {
            return comp(lhs.first, rhs.first);
        }
    };

  public:
    typedef Key                                       key_type;
    typedef T                                         mapped_type;
    typedef pair<const Key, mapped_type>              value_type;
    typedef size_t                                    size_type;
    typedef std::ptrdiff_t                            difference_type;
    typedef Compare                                   key_compare;
    typedef Comp_val                                  value_compare;
    typedef Alloc                                     allocator_type;
    typedef typename Alloc::reference                 reference;
    typedef typename Alloc::const_reference           const_reference;
    typedef typename Alloc::pointer                   pointer;
    typedef typename Alloc::const_pointer             const_pointer;
    // typedef MyBidirectionalIterator<value_type>       iterator;
    // typedef MyBidirectionalIterator<const value_type> const_iterator;
    // typedef my_rev_it<iterator>                     const_iterator;
    // typedef my_rev_it<const_iterator>                     const_iterator;

    private:
      avlTree<value_type> _tree;
    public:
      explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
      {

      };

};

// value compare not yet