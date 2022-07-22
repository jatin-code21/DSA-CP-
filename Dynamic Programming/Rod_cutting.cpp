#include <bits/stdc++.h>
using namespace std;

// Recursive solution
int max_profit(vector<int> &prices, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;
        int cur_ans = prices[i] + max_profit(prices, n - cut);
        ans = max(ans, cur_ans);
    }

    return ans;
}

// Bottom-up solution
int max_profit_dp(vector<int> &prices, int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int len = 1; len <= n; len++)
    {
        int ans = INT_MIN;
        for (int i = 0; i < len; i++)
        {
            int cut = i + 1;
            int cur_ans = dp[len - cut] + prices[i];
            ans = max(ans, cur_ans);
        }
        dp[len] = ans;
    }

    return dp[n];
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
    cin >> n; // length of the rod intiially
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    cout << max_profit_dp(prices, n) << "\n";
}