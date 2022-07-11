// Find the number of ways to reach the nth stair if max k jumps are allowed

#include <bits/stdc++.h>
using namespace std;

int numberOfWays(int n, int k, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    int ans = 0;
    for (int jump = 1; jump <= k; jump++)
    {
        ans += numberOfWays(n - jump, k, dp);
    }
    return ans;
}

// Time Complexity -> O(k^n);

int numberOfWaysTopDown(int n, int k, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != 0)
        return dp[n];

    int ans = 0;
    for (int jump = 1; jump <= k; jump++)
    {
        ans += numberOfWaysTopDown(n - jump, k, dp);
    }
    return dp[n] = ans;
}

// Time Complexity -> O(n*k);

int numberOfWaysBU(int n, int k)
{
    // itterative method;

    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int jump = 1; jump <= k; jump++)
        {
            if (i - jump >= 0)
            {
                dp[i] += dp[i - jump];
            }
        }
    }
    return dp[n];
}

// Time Complexity -> O(n*k);

int numberOfWaysOpt(int n, int k)
{
    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        dp[i] = 2 * dp[i - 1];
    }

    for (int i = k + 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    }

    return dp[n];
}

// Time Complexity -> O(n);

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> dp(1000, 0);
    cout << numberOfWays(n, k, dp) << "\n";
}
