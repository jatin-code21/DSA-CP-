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
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (char ch : to_string(i))
        {
            dp[i] = min(dp[i], dp[i - (ch - '0')] + 1);
        }
    }
    cout << dp[n];
}