#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <iostream>
#include <bits/stdc++.h>
#include <stdexcept>
#include "QuickFind.h"

using namespace std;

class Percolation
{
private:
    vector<vector<int>> matrix;
    QuickUnion qu;

    void validateCoord(int row, int col);
    int get_site_id(int row, int col);
    int virtual_top_site;
    int virtual_bottom_site;
    int number_of_open_sites;

public:
    Percolation(int n);

    // opens the site (row, col) if it is not open already
    void open(int row, int col);

    // is the site open?
    bool isOpen(int row, int col);

    // is the site full?
    // " A full site is an open site that can be connected to an open site in the top row via a chain of
    //   neighboring (left, right, up, down) open sites."
    bool isFull(int row, int col);

    // number of open sites
    int numberOfOpenSites();

    // does the system percolate?
    bool percolates();

    // access site (considering bounds) always closed if outside bounds
    bool site_at();

    // print status
    void print();
};

Percolation::Percolation(int n) : qu((n * n) + 2), number_of_open_sites(0)
{
    if (n <= 0)
    {
        throw std::invalid_argument("Size of grid must be bigger than 0");
    }

    virtual_top_site = n * n;          // Second to last element in QU
    virtual_bottom_site = (n * n) + 1; // Last element in QU

    //Initialize all the elements closed n*n matrix
    std::vector<std::vector<int>> ori(
        n,
        std::vector<int>(n, 0));

    matrix = ori;

    // Connect both virtual_top_site and virtual_bottom_site to the first and last row
    for (int i = 0; i < n; ++i)
    {
        qu.create_union(matrix[0][i], virtual_top_site);
        qu.create_union(matrix[n - 1][i], virtual_bottom_site);
    }
}

bool Percolation::isOpen(int row, int col)
{
    validateCoord(row, col);
    // Open = 1, Closed = 0
    return matrix[row][col] == 1;
};

void Percolation::validateCoord(int row, int col)
{
    if (row >= matrix[0].size() || row < 0 || col >= matrix[0].size() || col < 0)
    {
        throw std::invalid_argument("Invalid coordinate in grid");
    }
}

bool Percolation::isFull(int row, int col)
{
    // If root of this site == virtualTopSite
    return qu.connected(get_site_id(row, col), virtual_top_site);
}

int Percolation::get_site_id(int row, int col)
{
    // Ej: 1,2   1*4 + 2 = 6
    return row * matrix[0].size() + col;
}

void Percolation::print()
{
    for (auto ele : matrix)
    {
        for (auto site : ele)
        {
            cout << site << " ";
        }
        cout << endl;
    }
}

#endif