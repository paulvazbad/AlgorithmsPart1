#include <iostream>
using namespace std;
class QuickUnion
{
private:
    int *_id;
    int _number_of_elements;

public:
    QuickUnion(int number_of_elements);
    bool connected(int p, int q);
    void create_union(int p, int q);
    int root(int);
};

QuickUnion::QuickUnion(int number_of_elements)
{
    _id = new int[number_of_elements];
    for (int i = 0; i < number_of_elements; i++)
    {
        _id[i] = i;
    }
    _number_of_elements = number_of_elements;
}
int QuickUnion::root(int q){
    while(_id[q]!= q){
        q = _id[q];
    }
    return q;
}

bool QuickUnion::connected(int p, int q)
{
    return root(q) == root(p);
}

void QuickUnion::create_union(int p, int q)
{
    int root_p = root(p);
    int root_q = root(q);
    _id[root_p] = root_q; 
}

int main(){
    QuickUnion QF(5);
    QF.create_union(2,3);
    QF.create_union(3,1);
    std::cout<<(QF.connected(2,1)? "YES" : "NO") <<endl;
    return 0;
}