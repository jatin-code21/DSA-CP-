#include <bits/stdc++.h>
using namespace std;

int minPathSUm(int i, int j, vector<vector<int>> &v)
{
    int n = v.size();
    if (i == n - 1)
    {
        return v[n - 1][j];
    }
    int d = v[i][j] + minPathSUm(i + 1, j, v);
    int dg = v[i][j] + minPathSUm(i + 1, j + 1, v);
    return min(d, dg);
}

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
    vector<vector<int>> v(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int ele;
            cin >> ele;
            v[i].push_back(ele);
        }
    }
    // cout << minPathSUm(0, 0, v);
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = v[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int d = v[i][j] + dp[i + 1][j];
            int dg = v[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(d, dg);
        }
    }
    cout << dp[0][0];
}