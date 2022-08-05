#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int min_jump(vector<int> &v, int n, vector<int> &dp, int i)
{
    if (i == n - 1)
        return 0;
    if (i >= n)
        return INT_MAX;

    if (dp[i] != 0)
        return dp[i];

    int steps = INT_MAX;
    int max_jump = v[i];
    for (int jump = 1; jump <= max_jump; jump++)
    {
        int next_cell = i + jump;
        int subProb = min_jump(v, n, dp, next_cell);
        if (subProb != INT_MAX){
            steps = min(steps, subProb + 1);
        }
    }
    return dp[i] = steps;
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
    vector<int> v(n);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << min_jump(v,n,dp,0) << "\n";
}