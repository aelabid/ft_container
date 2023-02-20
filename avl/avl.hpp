#pragma once

#include<iostream>
template<class T>
class avlTree
{
    public:
    typedef struct s_tree
    {
        T   val;
        struct s_tree *right;
        struct s_tree *left;
        int balance;
    }	_t_tree;
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
        _t_tree    *new_node(T val)
        {
            _t_tree *my_new_node = _alloc.allocate(1);
            _alloc.construct(my_new_node, (_t_tree){val, NULL, NULL, 0});
            return my_new_node;
        }

        void    left_root_right(_t_tree *tree)
        {
            if(!tree)
                return;
            left_root_right(tree->left);
            std::cout<<tree->val<<std::endl;
            left_root_right(tree->right);
        }
        int    calcule_height_one_node(_t_tree *tree)
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
        
        int calcule_balance_for_one_node(_t_tree *tree)
        {
            if(!tree)
                return(0);
            int leftH;
            int rightH;
            leftH = calcule_height_one_node(tree->left);
            rightH = calcule_height_one_node(tree->right);
            return(rightH - leftH);
        }

        void    calcule_balance_for_all_nodes(_t_tree *tree)
        {
            if(!tree)
                return ;
            calcule_balance_for_all_nodes(tree->left);
            tree->balance = calcule_balance_for_one_node(tree);
            calcule_balance_for_all_nodes(tree->right);
        }

        _t_tree *right_rotation(_t_tree *tree)
        {
            if(!tree->left)
                return tree;
            _t_tree *tmp;
            tmp = tree->left;
            tree->left = tmp->right;
            tmp->right = tree;
            return (tmp);
        }
        _t_tree *left_rotation(_t_tree *tree)
        {
            if(!tree->right)
                return tree;
            _t_tree *tmp;
            tmp = tree->right;
            tree->right = tmp->left;
            tmp->left = tree;
            return (tmp);
        }
        void    left_right_root(_t_tree *tree)
        {
            if(!tree)
                return;
            left_right_root(tree->left);
            left_right_root(tree->right);
            std::cout<<tree->val<<std::endl;
        }
        _t_tree    *ft_balance(_t_tree *tree, int balance, T val)
        {
            if(tree->left)
            {
                if (balance < -1 && val < tree->left->val)
                {
                    // std::cout<<"here";
                    tree = right_rotation(tree);
                }
                if (balance < -1 && val > tree->left->val)
                {
                    tree->left = left_rotation(tree->left);
                    return right_rotation(tree);
                }
            }
            if(tree->right)
            {
                if(balance > 1 && val > tree->right->val)
                    return left_rotation(tree);
                if (balance > 1 && val < tree->right->val)
                {
                    tree->right = right_rotation(tree->right);
                    return left_rotation(tree);
                }
            }
            return (tree);
        }
        _t_tree *insert(_t_tree *tree, T val)
        {
            if (!tree)
                tree = new_node(val);
            else if(val > tree->val)
                tree->right = insert(tree->right, val);
            else
                tree->left = insert(tree->left, val);
            int balance = calcule_balance_for_one_node(tree);
            tree = ft_balance(tree, balance, val);
            return tree;
        };
        T   min_value(_t_tree *tree)
        {
            T val = tree->val;
            while(tree)
            {
                val = tree->val;
                tree = tree->left;
            }
            return val;
        }
        _t_tree *delete_node(_t_tree *tree, T val)
        {
            if (!tree)
                return (tree);
            else if (val < tree->val)
                tree->left = delete_node(tree->left, val);
            else if (val > tree->val)
                tree->right = delete_node(tree->right, val);
            else 
            {
                if (!tree->left || !tree->right)
                {
                    _t_tree *r, *l;
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
                    tree->val = tmp_val;
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
        _t_tree *_tr;
    private:
        std::allocator<_t_tree> _alloc;
};