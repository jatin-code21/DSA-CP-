#include <bits/stdc++.h>
using namespace std;

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
    vector<int> dp(n + 1, -1);
    dp[0] = 0; // both are base cases in case of recursion so we first here deal with base case;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // this is the returning function logic in recursion case;
    }
}

// This is also called as Tabulation method

// Time Complexity -> O(n)
// Space Complexity -> O(n) here its only O(n) because the recursion stack is not been there

// In this approach of converting to Tabulation from recursion is that we first go through base cases and then write the logic of same.