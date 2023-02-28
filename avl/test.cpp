#include"avl.hpp"
// #include<vector>
template <class T>
class comp
{
    public:
    bool operator()(T a, T b)
    {
        return (a<b);
    }
};

int main()
{
    // std::vector<int> v(1, 10);
    avlTree<int, int, comp<int> > tr;
    tr._tr = tr.insert(tr._tr, 50, 20).first;
    tr.insert(tr._tr, 35, 6);
    tr.insert(tr._tr, 60, 30);
    tr.insert(tr._tr, 30, 30);
    tr.insert(tr._tr, 40, 30);
    tr.insert(tr._tr, 55, 30);
    tr.insert(tr._tr, 70, 60);
    tr.insert(tr._tr, 29, 4);
    tr.insert(tr._tr, 32, 50);
    tr.insert(tr._tr,37, 50);
    tr.insert(tr._tr,52, 50);
    tr.insert(tr._tr,65, 50);
    tr.insert(tr._tr,75, 50);
    tr.insert(tr._tr,23, 50);
    tr.insert(tr._tr,62, 50);
    tr.insert(tr._tr,57, 50);
    tr.insert(tr._tr,42, 50);
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
    // tr.left_root_right(tr._tr);
    tr._tr = tr.get_next(tr._tr);
    std::cout<<tr.get_root(tr._tr)->node.first;
    // std::cout<<tr.get_next(tr._tr, 50);
}
