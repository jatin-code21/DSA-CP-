#include <bits/stdc++.h>
using namespace std;

int maxValue(vector<int> &weights, vector<int> &values, int wt, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weights[ind] <= wt)
            return values[ind];
        else
            return 0;
    }

    if (dp[ind][wt] != -1) return dp[ind][wt];
    int notTake = maxValue(weights, values, wt, ind - 1, dp);
    int take = INT_MIN;
    if (weights[ind] <= wt)
    {
        take = values[ind] + maxValue(weights, values, wt - weights[ind], ind - 1, dp);
    }

    return dp[ind][wt] = max(take, notTake);
}

int maxValueTabulation(vector<int> &weights, vector<int> &values, int wt)
{
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(wt + 1, 0));
    for (int i = weights[i]; i <= wt; i++)
    {
        dp[0][i] = values[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= wt; j++)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if (weights[i] <= j)
            {
                take = values[i] + dp[i - 1][j - weights[i]];    
            }
            dp[i][j] = max(take, notTake);        
        }
    }
    return dp[n - 1][wt];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n, wt;
    cin >> n >> wt;
    
    vector<int> weights(n);
    vector<int> values(n);
    vector<vector<int>> dp(n, vector<int>(wt + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    for (int i = 0; i < n; i++)
        cin >> values[i];

    cout << maxValueTabulation(weights, values, wt);
}