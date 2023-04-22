#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // the above array will contain only 0,1,2 and we have to sort it
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}