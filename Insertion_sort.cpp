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

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    cout << "Sorted Array is:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Worst Time Complexity is O(n*n)
// In this there are 2 parts left part sorted and right part unsorted so we take the element from unsorted part and go on comparing with sorted part and wherever it fits we place that element there
// The number of comparison here are less than the Bubble Sort so it is also called as optimization of Bubble