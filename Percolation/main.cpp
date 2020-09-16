#include <iostream>
#include "QuickFind.h"
#include "Percolation.h"

int main()
{
    Percolation percolation(3);
    percolation.print();

    // Test if full
    cout << (percolation.isFull(1, 1) ? "YES" : "NO") << endl;
    return 0;
}