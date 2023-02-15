#include"avl.hpp"

int main()
{
    avlTree<int> tr;
    tr._tr = tr.insert(tr._tr, 20);
    tr._tr = tr.insert(tr._tr, 11);
    tr._tr = tr.insert(tr._tr, 10);
    tr._tr = tr.insert(tr._tr, 15);
    tr._tr = tr.insert(tr._tr, 13);
    tr._tr = tr.insert(tr._tr, 16);
    tr._tr = tr.insert(tr._tr, 25);
    tr._tr = tr.insert(tr._tr, 28);
    tr.left_right_root(tr._tr);
}