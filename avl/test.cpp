#include"avl.hpp"

int main()
{
    avlTree<int> tr;
    tr._tr = tr.insert(tr._tr, 52);
    tr._tr = tr.insert(tr._tr, 60);
    tr._tr = tr.insert(tr._tr, 35);
    tr._tr = tr.insert(tr._tr, 30);
    tr._tr = tr.insert(tr._tr, 55);
    tr._tr = tr.insert(tr._tr, 29);
    tr._tr = tr.insert(tr._tr, 20);
    // tr._tr = tr.insert(tr._tr, 32);
    // tr._tr = tr.insert(tr._tr, 37);
    // tr._tr = tr.insert(tr._tr, 29);
    // tr._tr = tr.insert(tr._tr, 55);
    // tr._tr = tr.insert(tr._tr, 52);
    // tr._tr = tr.insert(tr._tr, 23);
    tr._tr = tr.delete_node(tr._tr, 55);
    tr.left_right_root(tr._tr);
}
