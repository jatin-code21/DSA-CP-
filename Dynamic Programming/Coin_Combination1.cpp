#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

// int numberOfWays(int x, vector<int> &c)
// {
//     int cnt = 0;
//     if (x == 0)
//     {
//         return 1;
//     }
//     for (int i = 0; i < c.size(); i++)
//     {
//         if (x - c[i] >= 0)
//         {
//             cnt += numberOfWays(x - c[i], c) % mod;
//         }
//     }
//     return cnt % mod;
// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = dp[i] % mod + dp[i - coins[j]] % mod;
            }
        }
    }
    cout << dp[x];
}