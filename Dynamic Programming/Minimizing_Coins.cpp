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
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] > i)
                continue;
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    if (dp[x] == 1e9)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;
}