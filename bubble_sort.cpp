#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Logic for Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        bool swap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap = true;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!swap)
            break;
    }
    cout << "Sorted array is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Worst Time Complexity is O(n*n);
// Here we compare the adjacent elements of array and if the right side element is smaller than left one than we swap the elements;
// So by the end of first pass we get the largest element at the end of array and we keep on performing the same until we get the sorted array;