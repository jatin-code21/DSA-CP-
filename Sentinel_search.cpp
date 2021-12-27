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
    // Sentinel Search logic
    int key;
    cout << "Enter the key you want to search: ";
    cin >> key;
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;
    while (arr[i] != key)
    {
        i++;
    }
    arr[n - 1] = last;
    if (i < n - 1 || last == key)
    {
        cout << "Key Founded"
             << "\n";
    }
    else
    {
        cout << "Key Not Found"
             << "\n";
    }
}