#pragma once

#include<iostream>
#include"../utils/pair.hpp"

template<class T, class V>
struct 	_t_tree
{
    ft::pair<T, V> node;
    struct _t_tree *right;
    struct _t_tree *left;
    int k;
    int balance;
};

template<class T, class V , class Compare = std::less<T>, class Alloc = std::allocator<_t_tree<T, V> >  >
class avlTree
{
    public:
    typedef Alloc   allocator;
    typedef T value_type;

    avlTree(){
        _tr = NULL;
        _i = 0;
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
            _alloc.construct(my_new_node, (_t_tree<T, V>){ft::make_pair(key, val), my_null(), my_null(), 1});
            return my_new_node;
        }
        _t_tree<T, V> *my_null()
        {
            _t_tree<T, V> *tmp = _alloc.allocate(1);
            tmp->left= NULL;
            tmp->right =  NULL;
            tmp->k = 0;
            return(tmp);
        }
        void    left_root_right(_t_tree<T, V>  *tree)
        {
            if(!tree || !tree->k)
                return;
            left_root_right(tree->left);
            std::cout<<tree->node.first<< " "<< tree->node.second<<std::endl;
            // if(tree->parent)
            //     std::cout<<"parent = "<< tree->parent->node.first<<std::endl;
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
            if(!tree || (!tree->left->k && !tree->right->k))
                return(0);
            int leftH;
            int rightH;
            leftH = calcule_height_one_node(tree->left);
            rightH = calcule_height_one_node(tree->right);
            return(rightH - leftH);
        }

        void    calcule_balance_for_all_nodes(_t_tree<T, V>  *tree)
        {
            if(!tree || (!tree->left->k && !tree->right->k))
                return ;
            calcule_balance_for_all_nodes(tree->left);
            tree->balance = calcule_balance_for_one_node(tree);
            calcule_balance_for_all_nodes(tree->right);
        }

        _t_tree<T, V>  *right_rotation(_t_tree<T, V>  *tree)
        {
            if(!tree->left || !tree->left->k)
                return tree;
            _t_tree<T, V>  *tmp;
            tmp = tree->left;
            tree->left = tmp->right;
            tmp->right = tree;
            return (tmp);
        }
        _t_tree<T, V>  *left_rotation(_t_tree<T, V>  *tree)
        {
            if (!tree->right || !tree->right->k)
                return tree;
            _t_tree<T, V>  *tmp;
            tmp = tree->right;
            tree->right = tmp->left;
            tmp->left = tree;
            return (tmp);
        }
        void    left_right_root(_t_tree<T, V>  *tree)
        {
            if(!tree || !tree->k)
                return;
            left_right_root(tree->left);
            left_right_root(tree->right);
            std::cout<<tree->node.first<< " " << tree->node.second<<std::endl;
        }
        _t_tree<T, V>     *ft_balance(_t_tree<T, V>  *tree, int balance, T key)
        {
            if(tree->left && tree->left->k)
            {
                if (balance < -1 && _cmp(key, tree->node.first))
                    tree = right_rotation(tree);
                else if (balance < -1 && _cmp(tree->node.first, key))
                {
                    tree->left = left_rotation(tree->left);
                    return right_rotation(tree);
                }
            }
            if(tree->right && tree->right->k)
            {
                if(balance > 1 && _cmp(tree->node.first, key))
                    return left_rotation(tree);
                else if (balance > 1 && _cmp(key, tree->node.first))
                {
                    tree->right = right_rotation(tree->right);
                    return left_rotation(tree);
                }
            }
            return (tree);
        }

        _t_tree<T, V>  *find(_t_tree<T, V>  *tree, T key)
        {
            if (!tree || !tree->k)
                return NULL;
            if(tree->node.first == key)
                return (tree);
            else if (_cmp(key, tree->node.first))
                return (find(tree->left, key));
            else if(_cmp(tree->node.first, key))
                return (find(tree->right, key));
            return NULL;
        } 
        ft::pair<_t_tree<T, V>*, bool> insert(_t_tree<T, V>  *tree, T key, V val)
        {
            ft::pair<_t_tree<T, V>*, bool> ret; 
            ret.second = 1;
            _t_tree<T, V>  *tmp = find(tree, key);
            if(tmp)
            {
                ret.second = 0;
            }
            tree = insert_utile(tree, key, val);
            ret.first = tree;
            return ret;
        }

        _t_tree<T, V>  *insert_utile(_t_tree<T, V>  *tree, T key, V val)
        {
            if (!tree ||!tree->k)
                tree = new_node(key, val);
            else if(_cmp(key, tree->node.first))
                tree->left = insert_utile(tree->left, key, val);
            else if(_cmp(tree->node.first, key))
                tree->right = insert_utile(tree->right, key, val);
            int balance = calcule_balance_for_one_node(tree);
            tree = ft_balance(tree, balance, key);
            return tree;
        };
        ft::pair<T, V>   min_value(_t_tree<T, V>  *tree)
        {
            ft::pair<T, V> key_val;
            key_val = ft::make_pair(tree->node.first, tree->node.second);
            while(tree && tree->k)
            {
                key_val = ft::make_pair(tree->node.first, tree->node.second); 
                tree = tree->left;
            }
            return key_val;
        }

        _t_tree<T, V>  *delete_node(_t_tree<T, V>  *tree, T key)
        {
            if (!tree || !tree->k)
                return (tree);
            else if (_cmp(key, tree->node.first))
                tree->left = delete_node(tree->left, key);
            else if (_cmp(tree->node.first, key))
                tree->right = delete_node(tree->right, key);
            else
            {
                if ((!tree->left && !tree->left->k) || (!tree->right && !tree->right->k))
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
                    ft::pair<T, V> key_val = min_value(tree->right);
                    tree->node.first = key_val.first;
                    tree->node.second = key_val.second;
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
            if (_cmp(key, tree->node.first))
            {
                if(tree->left->node.first == key)
                    return (tree);
                else
                    return (get_prev(tree->left, key));
            }
            else if(_cmp(tree->node.first, key))
            {
                if(tree->right->node.first == key)
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
            while(tree->left && tree->left->k == 1)
            {
                tree = tree->left;
            }
            return(tree);
        }
        _t_tree<T, V>   *get_begin_key(_t_tree<T, V> *tree)
        {
            if(!tree)
                return NULL;
            while(tree->left)
            {
                tree = tree->left;
            }
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
        _t_tree<T, V>   *get_end_key(_t_tree<T, V> *tree)
        {
            if (!tree)
                return NULL;
            while(tree->right && tree->right->k == 1)
                tree = tree->right;
            return(tree);
        }
        _t_tree<T, V>   *get_next(_t_tree<T, V> *tree, T key)
        {
            if(!tree || !tree->k)
                return NULL;
            if (key == tree->node.first && (tree->right && tree->right->k))
                return get_begin(tree->right);
            else
            {
                if(tree->left->k && get_end_key(tree->left)->node.first == key)
                    return tree;
                else if(_cmp(key, tree->node.first))
                    return get_next(tree->left, key);
                else if(_cmp(tree->node.first, key))
                    return get_next(tree->right, key);

            }
            return(NULL);
        }
        size_t get_size(_t_tree<T, V> *tree)
        {
            if (tree == NULL)
                return 0;
            else
                return(get_size(tree->left) + 1 + get_size(tree->right));
        }
        void    clear(_t_tree<T, V> *tree)
        {
            if (!tree || !tree->k)
                return ;
            clear(tree->left);
            _alloc.destroy(tree);
            _alloc.deallocate(tree, 1);
            clear(tree->right);
        }
        _t_tree<T, V>*   get_prev_key(_t_tree<T, V> *tree, T key)
        {
            if(tree->node.first == key)
                    return(get_end_key(tree->left));
            if (_cmp(key, tree->node.first))
            {
                if(tree->right && get_begin(tree->right)->node.first == key)
                    return tree;
                return (get_prev_key(tree->left, key));
            }
            else if (_cmp(tree->node.first, key))
            {
                if(tree->right && get_begin(tree->right)->node.first == key)
                    return tree;
            return get_prev_key(tree->right, key);
            }
            return NULL;
        };
        _t_tree<T, V>* get_max_key(_t_tree<T, V>* tree, T key)
        {
            while (tree && tree->k)
            {
                if(tree->node.first < key && tree->right->k)
                    tree = tree->right;
                else if(tree->node.first > key && tree->left->k)
                    tree = tree->left;
                else
                    break;                
            }
            if (tree->node.first < key)
                tree = get_end(tree);
            return tree;
        }
        _t_tree<T, V>* get_upper_bound(_t_tree<T, V>* tree, T key)
        {
            while(tree && tree->k)
            {
                if (tree->node.first > key && tree->left->k && get_end_key(tree->left)->node.first < key)
                    return get_end_key(tree->left);
                else if (tree->node.first > key && tree->left->k && get_end_key(tree->left)->node.first > key)
                    tree = tree->left;
                else if (tree->node.first < key && tree->right->k && get_begin(tree->right)->node.first > key)
                    return get_begin(tree->right);
                else if (tree->node.first < key && tree->left->k && get_end_key(tree->left)->node.first < key)
                    tree = tree->right;
            }
            return tree;
        }
        _t_tree<T, V>  *_tr;
    private:
        std::allocator<_t_tree<T, V> > _alloc;
        Compare                         _cmp;
        int                               _i;
};