#ifndef QUICKFIND_H
#define QUICKFIND_H
#include <iostream>

using namespace std;
class QuickUnion
{
private:
    int *_id;
    int _number_of_elements;
    int *size_of_trees;

public:
    QuickUnion(int number_of_elements);
    bool connected(int p, int q);
    void create_union(int p, int q);
    int root(int);
};

QuickUnion::QuickUnion(int number_of_elements)
{
    _id = new int[number_of_elements];
    size_of_trees = new int[number_of_elements];
    for (int i = 0; i < number_of_elements; i++)
    {
        _id[i] = i;
        size_of_trees[i] = 1;
    }
    _number_of_elements = number_of_elements;
}
int QuickUnion::root(int q)
{
    while (_id[q] != q)
    {
        _id[q] = _id[_id[q]];
            q = _id[q];
    }
    return q;
}

bool QuickUnion::connected(int p, int q)
{
    int root_p = root(p);
    int root_q = root(q);
    return root_q == root_p;
}

void QuickUnion::create_union(int p, int q)
{
    int root_p = root(p);
    int root_q = root(q);
    if (root_p == root_q)
        return;

    if (size_of_trees[root_p] < size_of_trees[root_q])
    {
        _id[root_p] = root_q;
        size_of_trees[root_q] += size_of_trees[root_p];
    }
    else
    {
        _id[root_q] = root_p;
        size_of_trees[root_p] += size_of_trees[root_q];
    }
    _id[root_p] = root_q;
}

#endif //QUICKFIND_H