#pragma once

#include<iostream>
#include"../utils/pair.hpp"

template<class T, class V>
struct 	_t_tree
{
    T   key;
    V   val;
    struct _t_tree *right;
    struct _t_tree *left;
    int balance;
};

template<class T, class V , class Compare = std::less<T>, class Alloc = std::allocator<_t_tree<T, V> >  >
class avlTree
{
    public:
    typedef Alloc   allocator;
    // typedef T       key;
    // typedef V       value;
    avlTree(){
        _tr = NULL;
    };
    avlTree& operator= (const avlTree& x)
    {
        // Guard self assignment
        if (this == &x)
            return *this;
        _tr = x._tr;
        return *this;
    }
    ~avlTree(){};
        _t_tree<T, V>     *new_node(T key, V val)
        {
            _t_tree<T, V>  *my_new_node = _alloc.allocate(1);
            _alloc.construct(my_new_node, (_t_tree<T, V> ){key, val, NULL, NULL, 0});
            return my_new_node;
        }

        void    left_root_right(_t_tree<T, V>  *tree)
        {
            if(!tree)
                return;
            left_root_right(tree->left);
            std::cout<<tree->key<< " "<< tree->val<<std::endl;
            left_root_right(tree->right);
        }
        int    calcule_height_one_node(_t_tree<T, V>  *tree)
        {
            int leftB;
            int rightB;
            if (!tree)
                return (0);
            else
            {
                leftB = calcule_height_one_node(tree->left);
                rightB = calcule_height_one_node(tree->right);
                if (leftB > rightB)
                    return (leftB + 1);
                else
                    return (rightB + 1);
            }
        }

        int calcule_balance_for_one_node(_t_tree<T, V>  *tree)
        {
            if(!tree)
                return(0);
            int leftH;
            int rightH;
            leftH = calcule_height_one_node(tree->left);
            rightH = calcule_height_one_node(tree->right);
            return(rightH - leftH);
        }

        void    calcule_balance_for_all_nodes(_t_tree<T, V>  *tree)
        {
            if(!tree)
                return ;
            calcule_balance_for_all_nodes(tree->left);
            tree->balance = calcule_balance_for_one_node(tree);
            calcule_balance_for_all_nodes(tree->right);
        }

        _t_tree<T, V>  *right_rotation(_t_tree<T, V>  *tree)
        {
            if(!tree->left)
                return tree;
            _t_tree<T, V>  *tmp;
            tmp = tree->left;
            tree->left = tmp->right;
            tmp->right = tree;
            return (tmp);
        }
        _t_tree<T, V>  *left_rotation(_t_tree<T, V>  *tree)
        {
            if (!tree->right)
                return tree;
            _t_tree<T, V>  *tmp;
            tmp = tree->right;
            tree->right = tmp->left;
            tmp->left = tree;
            return (tmp);
        }
        void    left_right_root(_t_tree<T, V>  *tree)
        {
            if(!tree)
                return;
            left_right_root(tree->left);
            left_right_root(tree->right);
            std::cout<<tree->key<< " " << tree->val<<std::endl;
        }
        _t_tree<T, V>     *ft_balance(_t_tree<T, V>  *tree, int balance, T key)
        {
            if(tree->left)
            {
                if (balance < -1 && _cmp(key, tree->key))
                    tree = right_rotation(tree);
                else if (balance < -1 && _cmp(tree->key, key))
                {
                    tree->left = left_rotation(tree->left);
                    return right_rotation(tree);
                }
            }
            if(tree->right)
            {
                if(balance > 1 && _cmp(tree->key, key))
                    return left_rotation(tree);
                else if (balance > 1 && _cmp(key, tree->key))
                {
                    tree->right = right_rotation(tree->right);
                    return left_rotation(tree);
                }
            }
            return (tree);
        }

        T find(_t_tree<T, V>  *tree, T key)
        {
            if (!tree)
                return (T)NULL;
            if(tree->key == key)
                return (key);
            else if (_cmp(key, tree->key))
                return (find(tree->left, key));
            else if(_cmp(tree->key, key))
                return (find(tree->right, key));
            return (T)NULL;
        }

        _t_tree<T, V>  *insert(_t_tree<T, V>  *tree, T key, V val)
        {
            T   tmp = find(tree, key);
            if(tmp)
                tree = delete_node(tree, tmp);
            tree = insert_utile(tree, key, val);
            return tree;
        }

        _t_tree<T, V>  *insert_utile(_t_tree<T, V>  *tree, T key, V val)
        {
            if (!tree)
                tree = new_node(key, val);
            else if(_cmp(key, tree->key))
                tree->left = insert_utile(tree->left, key, val);
            else if(_cmp(tree->key, key))
                tree->right = insert_utile(tree->right, key, val);
            int balance = calcule_balance_for_one_node(tree);
            tree = ft_balance(tree, balance, key);
            return tree;
        };
        pair<T, V>   min_value(_t_tree<T, V>  *tree)
        {
            pair<T, V> key_val;
            key_val = make_pair(tree->key, tree->val);
            while(tree)
            {
                key_val = make_pair(tree->key, tree->val); 
                tree = tree->left;
            }
            return key_val;
        }

        _t_tree<T, V>  *delete_node(_t_tree<T, V>  *tree, T key)
        {
            if (!tree)
                return (tree);
            else if (_cmp(key, tree->key))
                tree->left = delete_node(tree->left, key);
            else if (_cmp(tree->key, key))
                tree->right = delete_node(tree->right, key);
            else 
            {
                if (!tree->left || !tree->right)
                {
                    _t_tree<T, V>  *r, *l;
                    r = tree->right;
                    l = tree->left;   
                    _alloc.destroy(tree);
                    _alloc.deallocate(tree, 1);
                    if (l == NULL)
                        return (r);
                    else if (r == NULL)
                        return (l);
                }
                else
                {
                    pair<T, V> key_val = min_value(tree->right);
                    tree->key = key_val.first;
                    tree->val = key_val.second;
                    tree->right = delete_node(tree->right, key_val.first);
                }
            }
            int balance = calcule_balance_for_one_node(tree);
            if(balance == 2 && calcule_balance_for_one_node(tree->left) == -1)
                return left_rotation(tree);
            else if (balance == 2 && calcule_balance_for_one_node(tree->left) == -1)
            {
                tree->left = right_rotation(tree->left);
                return left_rotation(tree);
            }
            else if (balance == -2 && calcule_balance_for_one_node(tree->right) <= 0)
                return right_rotation(tree);
            else if (balance == -2 && calcule_balance_for_one_node(tree->right) == 1)
            {
                tree->right = left_rotation(tree->right);
                return right_rotation(tree);
            }
            return(tree);
        }

        _t_tree<T, V>   *get_prev(_t_tree<T, V> *tree, T key)
        {
            if (_cmp(key, tree->key))
            {
                if(tree->left->key == key)
                    return (tree);
                else
                    return (get_prev(tree->left, key));
            }
            else if(_cmp(tree->key, key))
            {
                if(tree->right->key == key)
                    return (tree);
                else
                    return (get_prev(tree->right, key));
            }
            return NULL;
        }
        _t_tree<T, V>   *get_begin(_t_tree<T, V> *tree)
        {
            if(!tree)
                return NULL;
            while(tree->left)
                tree = tree->left;
            return(tree);
        }
        _t_tree<T, V>   *get_end(_t_tree<T, V> *tree)
        {
            if (!tree)
                return NULL;
            while(tree->right)
                tree = tree->right;
            return(tree);
        }
        _t_tree<T, V>   *get_next(_t_tree<T, V> *tree)
        {
            if(!tree)
                return NULL;
            else if (tree->right)
                return get_begin(tree->right);
        }
        int get_size(_t_tree<T, V> *tree)
        {
            if (tree == NULL)
                return 0;
            else
                return(get_size(tree->left) + 1 + get_size(tree->right));
        }
        void    clear(_t_tree<T, V> *tree)
        {
            if (!tree)
                return ;
            clear(tree->left);
            clear(tree->right);
            _alloc.destroy(tree);
            _alloc.deallocate(tree, 1);
        }
        T   get_prev_key(_t_tree<T, V> *tree, T key)
        {
            if(tree->key == key)
                    return(get_end(tree->left)->key);
            if (_cmp(key, tree->key))
            {
                if(tree->right && get_begin(tree->right)->key == key)
                    return tree->key;
                return (get_prev_key(tree->left, key));
            }
            else if (_cmp(tree->key, key))
            {
                if(tree->right && get_begin(tree->right)->key == key)
                    return tree->key;
            return get_prev_key(tree->right, key);
            }
            return (T)NULL;
        };
        _t_tree<T, V>  *_tr;
    private:
        std::allocator<_t_tree<T, V> > _alloc;
        Compare                         _cmp;
};