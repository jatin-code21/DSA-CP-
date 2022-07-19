#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

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
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            v[i][j] = (ch == '.') ? 1 : 0;
        }
    }
    if (v[n - 1][n - 1] == 1)
        dp[n - 1][n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) // filling just last column
    {
        if (v[i][n - 1] == 0)
            dp[i][n - 1] = 0;
        else
        {
            dp[i][n - 1] += dp[i + 1][n - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) // filling just last row
    {
        if (v[n - 1][i] == 0)
            dp[n - 1][i] = 0;
        else
        {
            dp[n - 1][i] += dp[n - 1][i + 1];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (v[i][j] == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] += (dp[i + 1][j] % mod + dp[i][j + 1] % mod) % mod;
            }
        }
    }
    cout << dp[0][0];
}