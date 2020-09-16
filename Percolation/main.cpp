#include <iostream>
#include "QuickFind.h"
#include "Percolation.h"

int main()
{
    Percolation percolation(3);
    percolation.print();

    // Test if full
    cout << "TEST if full " << endl;
    cout << (percolation.isFull(0, 0) ? "YES" : "NO") << endl;
    cout << (percolation.isFull(1, 1) ? "YES" : "NO") << endl;
    cout << (percolation.isFull(2, 2) ? "YES" : "NO") << endl;

    cout << "Does it percolate? "<< (percolation.percolates() ? "YES" : "NO") << endl;

    // Test if open
    cout << "TEST if open " << endl;
    cout << (percolation.isOpen(0, 0) ? "YES" : "NO") << endl;
    cout << (percolation.isOpen(1, 1) ? "YES" : "NO") << endl;
    cout << (percolation.isOpen(2, 2) ? "YES" : "NO") << endl;

    cout << "Does it percolate? " << (percolation.percolates() ? "YES" : "NO") << endl;
    // Open middle col and check if percolates
    cout << "Open 1,1" << endl;
    percolation.open(1, 1);
    cout << "Does it percolate? " << (percolation.percolates() ? "YES" : "NO") << endl;
    percolation.open(2, 1);
    cout << "Does it percolate? " << (percolation.percolates() ? "YES" : "NO") << endl;
    percolation.open(0, 1);
    cout << "Does it percolate? " << (percolation.percolates() ? "YES" : "NO") << endl;
    return 0;
}