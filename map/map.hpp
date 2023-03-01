#pragma once
#include<iostream>
#include<map>
#include"../utils/pair.hpp"
#include"../iterators/vector_it.hpp"
#include"../iterators/map_it.hpp"
#include"../avl/avl.hpp"

template < class Key,  class T, 
  class Compare = std::less<Key>,
  class Alloc = std::allocator<ft::pair<const Key,T> > > 
class map
{
  public:
    typedef Key                                       key_type;
    typedef T                                         mapped_type;
    typedef ft::pair<const Key, mapped_type>              value_type;
    typedef size_t                                    size_type;
    typedef std::ptrdiff_t                            difference_type;
    typedef Compare                                   key_compare;
    // typedef Comp_val                                  value_compare;
    typedef Alloc                                     allocator_type;
    typedef typename Alloc::reference                 reference;
    typedef typename Alloc::const_reference           const_reference;
    typedef typename Alloc::pointer                   pointer;
    typedef typename Alloc::const_pointer             const_pointer;
    typedef MyBidirectionalIterator<avlTree<key_type, mapped_type, key_compare, Alloc>, _t_tree<Key, T>*, Key, T>       iterator;
    typedef MyBidirectionalIterator<avlTree<key_type, mapped_type, key_compare, Alloc>, _t_tree<Key, T>*, Key, T>       const_iterator;
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
      // -------------------------------Constructors-------------------------------------//
        // ------------------------ default constructor ------------------------ //

      explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
      {
        _alloc = alloc;
        _tree._tr = NULL;
        i = 0;
      };

        // ------------------------ range constructor ------------------------ //

      // template <class InputIterator>
      // map (InputIterator first, InputIterator last,
      //   const key_compare& comp = key_compare(),
      //     const allocator_type& alloc = allocator_type())
      // {
        
      // };

        // ------------------------ copy constructor ------------------------ //

      // map (const map& x)
      // {

      // };

        // ------------------------ Destructor ------------------------ //
        ~map()
        {

        }
    // ------------------------Operator Overloading------------------------ //

     map& operator= (const map& x)
     {

     };



    // ------------------------Capacity------------------------ //
    bool empty() const
    {
      if(_tree)
        return false;
      return true;
    }
    size_type size() const
    {
      return (_tree.get_size(_tree._tr));
    };
    size_type max_size() const
    {
      return _alloc.max_size();
    };

    // ------------------------Iterators------------------------ //
    iterator begin()
    {
      return (iterator(_tree, _tree.get_begin(_tree._tr)));
    };
    const_iterator begin() const
    {
      return (const_iterator(_tree, _tree.get_begin(_tree._tr)));
    };
    iterator end()
    {
      return (iterator(_tree, _tree.get_end(_tree._tr)));
    };
    const_iterator end() const
    {
      return (const_iterator(_tree, _tree.get_end(_tree._tr)));
    };

    // ------------------------Modifiers------------------------ //
    ft::pair<iterator,bool> insert( const value_type& value )
    {
      ft::pair<_t_tree<key_type, mapped_type>*, bool> tmp;
      if( i == 0)
      {
        tmp = _tree.insert(_tree._tr, value.first, value.second);
        _tree._tr = tmp.first;
      }
      else
        tmp = _tree.insert(_tree._tr, value.first, value.second);
      return(ft::make_pair(iterator(_tree, tmp.first), tmp.second));
    };

    private:
      int i;
      avlTree<key_type, mapped_type, key_compare, Alloc> _tree;
      allocator_type  _alloc;
};

// value compare not yet