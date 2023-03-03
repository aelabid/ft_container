#pragma once
#include<iostream>
#include<map>
#include"../utils/pair.hpp"
#include"../iterators/vector_it.hpp"
#include"../iterators/map_it.hpp"
#include"../avl/avl.hpp"
#include"../includes/vector.hpp"
namespace ft {

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
    typedef ft::MyBidirectionalIterator<avlTree<key_type, mapped_type, key_compare, Alloc>, _t_tree<Key, T>*, Key, T>       iterator;
    typedef ft::MyBidirectionalIterator<const avlTree<key_type, mapped_type, key_compare, Alloc>, _t_tree<Key, T>*, Key, T>       const_iterator;
    typedef ft::reverse_iterator_m<avlTree<key_type, mapped_type, key_compare, Alloc>, _t_tree<Key, T>*, Key, T>                     reverse_iterator;
    typedef ft::reverse_iterator_m<const avlTree<key_type, mapped_type, key_compare, Alloc>, _t_tree<Key, T>*, Key, T>                     const_reverse_iterator;
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
        _cmp =comp;
      };

        // ------------------------ range constructor ------------------------ //

      template <class InputIterator>
      map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
          const allocator_type& alloc = allocator_type())
      {
        _cmp = comp;
        _alloc = alloc;
        insert(first, last);
      };
        // ------------------------ copy constructor ------------------------ //

      map (const map& x)
      {
        this->_alloc = x._alloc;
        this->_tree = x._tree;
        this->i = x.i;
        this->_cmp = x._cmp;
      };

        // ------------------------ Destructor ------------------------ //
        ~map()
        {
          _tree.clear(_tree._tr);
        }
    // ------------------------Operator Overloading------------------------ //

     map& operator= ( map& x)
     {
        if (&x == this)
          return *this;
        _cmp = x._cmp;
        _alloc = x._alloc;
        _tree.clear(_tree._tr);
        insert(x.begin(), x.end());
        return *this;
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
      if(!_tree._tr)
        return iterator(_tree, _tree._tr);
      return (iterator(_tree, _tree.get_begin(_tree._tr)));
    };
    const_iterator begin() const
    {
      if(!_tree._tr)
        return const_iterator(_tree, _tree._tr);
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
    reverse_iterator rbegin()
    {
      return (reverse_iterator(_tree, _tree.get_end_key(_tree._tr)));
    };
    const_reverse_iterator rbegin() const
    {
      return (const_reverse_iterator(_tree, _tree.get_end_key(_tree._tr)));
    };
    reverse_iterator rend()
    {
      return (reverse_iterator(_tree, _tree.get_begin_key(_tree._tr)));
    };
    const_reverse_iterator rend() const
    {
      return (const_reverse_iterator(_tree, _tree.get_begin_key(_tree._tr)));
    };


    // ------------------------Element access------------------------ //
    mapped_type& operator[] (const key_type& k)
    {
      ft::pair<_t_tree<key_type, mapped_type>*, bool> tmp = _tree.insert(_tree._tr, k, mapped_type());
      _tree._tr = tmp.first;
      _t_tree<key_type, mapped_type>* _t = _tree.find(_tree._tr, k);
      return _t->node.second;
    };
    mapped_type& at (const key_type& k)
    {
      _t_tree<key_type, mapped_type>* _t = _tree.find(_tree._tr, k);
      if(!_t)
        throw std::out_of_range("");
      return _t->node.second;
    };
    const mapped_type& at (const key_type& k) const
    {
      at(k);
    };

    // ------------------------Modifiers------------------------ //
    ft::pair<iterator, bool> insert( const value_type& value )
    {
      ft::pair<_t_tree<key_type, mapped_type>*, bool> tmp = _tree.insert(_tree._tr, value.first, value.second);
      _tree._tr = tmp.first;
      _t_tree<key_type, mapped_type>* _t = _tree.find(_tree._tr, value.first);
      return(ft::make_pair(iterator(_tree, _t), tmp.second));
    };
    iterator insert (iterator position, const value_type& val)
    {
      ft::pair<_t_tree<key_type, mapped_type>*, bool> tmp = _tree.insert(_tree._tr, val.first, val.second);
      _tree._tr = tmp.first;
      _t_tree<key_type, mapped_type>* _t = _tree.find(_tree._tr, val.first);
      i = 1;
      return(iterator(_tree, _t));
    };
    template <class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
      while (first!=last)
      {
        insert(value_type(first->first, first->second));
        first++;
      }
      
    };
    void erase (iterator position)
    {
      _tree.delete_node(_tree._tr, position->first);
    };
    size_type erase (const key_type& k)
    {
      if(!_tree.find(_tree._tr, k))
        return 0;
      _tree.delete_node(_tree._tr, k);
      return 1;
    };
    void erase (iterator first, iterator last)
    {
      ft::vector<ft::pair<key_type, mapped_type> > t;
      for (iterator i = first; i != last; ++i) {
          t.push_back(ft::make_pair(i->first, i->second));
      }
      for (size_t i = 0; i < t.size(); ++i) {
          _tree.delete_node(_tree._tr, t[i].first);
      }
    };
    void clear()
    {
      _tree.clear(_tree._tr);
      _tree._tr = NULL;
    };

    // ------------------------Observers------------------------ //
    key_compare key_comp() const
    {
      return _cmp;
    };
    value_compare value_comp() const
    {
      value_compare v;
      return v;
    };

    // ------------------------Operations------------------------ //
    iterator find (const key_type& k)
    {
      _t_tree<key_type, mapped_type>* _t = _tree.find(_tree._tr, k);
      return iterator(_tree, _t);
    };
    const_iterator find (const key_type& k) const
    {
      _t_tree<key_type, mapped_type>* _t = _tree.find(_tree._tr, k);
      return const_iterator(_tree, _t);
    };
    size_type count (const key_type& k) 
    {
      if(!_tree.find(_tree._tr, k))
        return 0;
      return 1;
    };
    iterator lower_bound (const key_type& k)
    {
      if(_tree.find(_tree._tr, k))
        return iterator(_tree, _tree.find(_tree._tr, k));
      else
        return iterator(_tree, _tree.get_max_key(_tree._tr, k));
    };
    const_iterator lower_bound (const key_type& k) const
    {
      if(_tree.find(_tree._tr, k))
        return const_iterator(_tree, _tree.find(_tree._tr, k));
      else
        return const_iterator(_tree, _tree.get_max_key(_tree._tr, k));

    };
    iterator upper_bound (const key_type& k)
    {
      // if(_tree.find(_tree._tr, k))
      //   return iterator(_tree,_tree.get_next(_tree._tr, k));
      // else
        return iterator(_tree, _tree.get_upper_bound(_tree._tr, k));
    };
    const_iterator upper_bound (const key_type& k) const
    {
      if(_tree.find(_tree._tr, k))
        return iterator(_tree,_tree.get_next(_tree._tr, k));
      return const_iterator(_tree, _tree.get_upper_bound(_tree._tr, k));
    };

    // ------------------------Allocator------------------------ //
    allocator_type get_allocator() const
    {
      return _alloc;
    };
    private:
      int i;
      allocator_type  _alloc;
      key_compare _cmp;
      avlTree<key_type, mapped_type, key_compare, Alloc> _tree;
};
}
// value compare not yet