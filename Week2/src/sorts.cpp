#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        j = i;
        // Exchange with elements to the left that are bigger
        for (int k = i; k >= 0; k--)
        {
            if (arr[k] > arr[j])
            {
                // Element is greater then swap
                int swap = arr[j];
                arr[j] = arr[k];
                arr[k] = swap;
                j = k;
            }
        }
    }
}

void merge(int arr[], int auxiliary[], int low, int mid, int high)
{
    for (int i = low; i <= high; i++)
    {
        auxiliary[i] = arr[i];
    }
    int i = low, j = mid + 1;

    for (int k = low; k <= high; k++)
    {
        if (i > mid)
        {
            arr[k] = auxiliary[j++];
        }
        else if (j > high)
        {
            arr[k] = auxiliary[i++];
        }
        else if (auxiliary[i] < auxiliary[j])
        {
            arr[k] = auxiliary[i++];
        }
        else
        {
            arr[k] = auxiliary[j++];
        }
    }
}

void merge_sort(int arr[], int aux[], int low, int high)
{
    if (high <= low)
        return;
    int mid = low + (high - low) / 2;
    merge_sort(arr, aux, low, mid);
    merge_sort(arr, aux, mid + 1, high);
    merge(arr, aux, low, mid, high);
}

int main()
{
    int arr[6] = {1, 4, 6, 2, 3, 5};
    int aux[6];
    merge_sort(arr, aux, 0, 6 - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}