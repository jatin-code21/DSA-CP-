#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q; // n is the size of array and q is queries
    cin >> n >> q;
    int arr[n] = {0};
    int val = 2;
    while (q--)
    {
        int left, right;
        cin >> left >> right;
        // Logic for Scanline
        arr[left] += val;
        arr[right + 1] -= val;
    }
    // Prefix Sum Concept/logic
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            arr[i] += arr[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}