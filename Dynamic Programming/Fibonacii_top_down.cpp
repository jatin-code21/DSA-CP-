#include <bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
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
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibo(n, dp);
}

// Time Complexity -> O(n);
// Space Complexity -> O(n) because of recursion stack + O(n) auxilary space