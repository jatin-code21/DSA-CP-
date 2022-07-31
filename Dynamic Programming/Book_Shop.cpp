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
    vector<int> prices(n + 1), pages(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }
    // books-> rows and budget->columns
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (prices[i] > j)
                dp[i][j] = dp[i - 1][j]; // this means at  i- 1th book with budget j whatever we can buy
            else                         // we have the budget
            {
                dp[i][j] = max(dp[i - 1][j], pages[i] + dp[i - 1][j - prices[i]]);
            }
        }
    }
    cout << dp[n][x];
}