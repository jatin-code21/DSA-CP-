#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[8] = {-2, 10, 1, 3, 2, -1, 4, 5};
    int min_sum = INT_MAX;
    int sum = 0;
    int k = 3;

    for (int j = 0; j < k; j++)
    {
        sum += arr[j];
    }
    min_sum = min(sum, min_sum);
    for (int i = 1; i < 8 - k + 1; i++)
    {
        sum -= arr[i - 1];
        sum += arr[i + 1];
    }
    min_sum = min(sum, min_sum);
    cout << min_sum;
}