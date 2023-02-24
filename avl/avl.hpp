#pragma once

#include<iostream>
template<class T, class V>
struct 	_t_tree
{
    T   key;
    V   val;
    struct _t_tree *right;
    struct _t_tree *left;
    int balance;
};

template<class T, class V, class Alloc = std::allocator<_t_tree<T, V> > >
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
            std::cout<<tree->key<<std::endl;
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
                if (balance < -1 && key < tree->left->key)
                {
                    // std::cout<<"here";
                    tree = right_rotation(tree);
                }
                if (balance < -1 && key > tree->left->key)
                {
                    tree->left = left_rotation(tree->left);
                    return right_rotation(tree);
                }
            }
            if(tree->right)
            {
                if(balance > 1 && key > tree->right->key)
                    return left_rotation(tree);
                if (balance > 1 && key < tree->right->key)
                {
                    tree->right = right_rotation(tree->right);
                    return left_rotation(tree);
                }
            }
            return (tree);
        }
        _t_tree<T, V>  *insert(_t_tree<T, V>  *tree, T key, V val)
        {
            if (!tree)
                tree = new_node(key, val);
            else if(key > tree->key)
                tree->right = insert(tree->right, key, val);
            else
                tree->left = insert(tree->left, key, val);
            int balance = calcule_balance_for_one_node(tree);
            tree = ft_balance(tree, balance, key);
            return tree;
        };
        T   min_value(_t_tree<T, V>  *tree)
        {
            T key = tree->key;
            while(tree)
            {
                key = tree->key;
                tree = tree->left;
            }
            return key;
        }
        _t_tree<T, V>  *delete_node(_t_tree<T, V>  *tree, T key)
        {
            if (!tree)
                return (tree);
            else if (key < tree->key)
                tree->left = delete_node(tree->left, key);
            else if (key > tree->key)
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
                    T tmp_val = min_value(tree->right);
                    tree->key = tmp_val;
                    tree->right = delete_node(tree->right, tmp_val);
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
        _t_tree get_next(_t_tree<T, V> *tree)
        {
            if(tree->right == NULL)
                return tree;
            else
                return tree->right;
        }
         
        _t_tree<T, V>  *_tr;
    private:
        std::allocator<_t_tree<T, V> > _alloc;
};