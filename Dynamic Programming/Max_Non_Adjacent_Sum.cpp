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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n, 0);
    dp[0] = max(dp[0], 0);
    dp[1] = max(0, max(v[0], v[1]));
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], v[i] + dp[i - 2]);
    }
    cout << dp[n - 1] << "\n";
}