#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int sum = 0, cnt = 0;
    unordered_map<int, int> prevSum;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];

        if (sum == k)
            cnt++;
        if (prevSum.find(sum - k) != prevSum.end())
        {
            cnt += prevSum[sum - k];
        }
        prevSum[sum]++;
    }
    cout << cnt << "\n";
}