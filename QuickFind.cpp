#include <iostream>
using namespace std;
class QuickFind
{
private:
    int *_id;
    int _number_of_elements;

public:
    QuickFind(int number_of_elements);
    bool connected(int p, int q);
    void create_union(int p, int q);
};

QuickFind::QuickFind(int number_of_elements)
{
    _id = new int[number_of_elements];
    for (int i = 0; i < number_of_elements; i++)
    {
        _id[i] = i;
    }
    _number_of_elements = number_of_elements;
}

bool QuickFind::connected(int p, int q)
{
    return _id[p] == _id[q];
}

void QuickFind::create_union(int p, int q)
{
    for (int i = 0; i < _number_of_elements; i++)
    {
        if (_id[i] == _id[p])
        {
            _id[i] = _id[q];
        }
    }
}

int main(){
    QuickFind QF(5);
    std::cout<<"Done"<<endl;
    return 0;
}