#include <bits/stdc++.h>
using namespace std;

// Top Down
int coinChangeTD(int m, vector<int> &a, int cnt)
{
    if (m == 0)
        return 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (m - a[i] >= 0)
        {
            cnt = min(cnt, coinChangeTD(m - a[i], a, cnt));
        }
    }
    return cnt + 1;
}

// Bottom Up Approach
int coinChange(int m, vector<int> &a)
{
    vector<int> dp(m + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < a.size(); j++)
        {
            if (i - a[j] >= 0 && dp[i - a[j]] != INT_MAX) // and condition is necsessary to hanlde the edge cases that is when its not possible to calculate the particular coin;
            {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    return dp[m] == INT_MAX ? -1 : dp[m];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n, m;
    cin >> n >> m;    // m is target coin required
    vector<int> a(n); // types of coin available
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = INT_MAX;
    cout << coinChangeTD(m, a, cnt) << "\n";
}