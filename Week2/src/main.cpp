#include <iostream>
#include "Deque.h"

using namespace std;

int main()
{
    Deque<int> dq;
    cout<<dq.size()<<endl;
    dq.addFirst(7);
    cout<<dq.removeFirst()<<endl;
    dq.addFirst(2);
    dq.addFirst(1);
    dq.print();
    dq.addLast(3);
    dq.print();
    dq.removeLast();
    dq.print();
    cout<<dq.removeLast()<<endl;
    dq.print();
    cout<<dq.removeLast()<<endl;
    dq.print();
    return 0;
}