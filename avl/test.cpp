#include"avl.hpp"
// #include<vector>
template <class T>
class comp
{
    public:
    bool operator()(T a, T b)
    {
        return (a>b);
    }
};

int main()
{
    // std::vector<int> v(1, 10);
    avlTree<int, int, comp<int> > tr;
    tr._tr = tr.insert(tr._tr, 2, 20);
    tr._tr = tr.insert(tr._tr, 4, 6);
    tr._tr = tr.insert(tr._tr, 3, 30);
    // tr._tr = tr.insert(tr._tr, 23, 30);
    // tr._tr = tr.insert(tr._tr, 66, 30);
    // tr._tr = tr.insert(tr._tr, 232, 30);
    // tr._tr = tr.insert(tr._tr, 1, 60);
    // tr._tr = tr.insert(tr._tr, 32, 30);
    // tr._tr = tr.insert(tr._tr, 2, 50);
    
    // tr._tr = tr.insert(tr._tr, 'd', 40);
    // tr._tr = tr.insert(tr._tr, 'a', 40);
    // tr._tr = tr.insert(tr._tr, 'e', 55);
    // tr._tr = tr.insert(tr._tr, 'b', 40);
    // tr._tr = tr.insert(tr._tr, 'f', 29);
    // tr._tr = tr.insert(tr._tr, 'c', 35);
    // tr._tr = tr.insert(tr._tr, 32);
    // tr._tr = tr.insert(tr._tr, 37);
    // tr._tr = tr.insert(tr._tr, 29);
    // tr._tr = tr.insert(tr._tr, 55);
    // tr._tr = tr.insert(tr._tr, 52);
    // tr._tr = tr.insert(tr._tr, 23);
    // tr._tr = tr.delete_node(tr._tr, 2);
    // tr._tr = tr.get_prev(tr._tr, 2);
    // tr.clear(tr._tr);
    tr.left_right_root(tr._tr);
    // std::cout<<tr.get_begin(tr._tr)->key;
}
