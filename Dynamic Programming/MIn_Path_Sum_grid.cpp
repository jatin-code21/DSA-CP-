#include <bits/stdc++.h>
using namespace std;

int minCost(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return v[i][j];
    }
    if (i < 0 || j < 0) return INT_MAX;
    if (dp[i][j] != -1) return dp[i][j];
    int up = v[i][j] + minCost(i - 1, j, v,dp);
    int left = v[i][j] + minCost(i, j - 1, v, dp);

    return dp[i][j] = min(up, left);
}

int minCostTabulation(vector<vector<int>> &v, vector<vector<int>> &dp)
{
    int n = v.size();
    int m = v[0].size();
    int up,left;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) dp[i][j] = v[i][j];
            else
            {
                if (i > 0) 
                {
                    up += dp[i - 1][j];
                } else up = INT_MAX;
                if (j > 0) 
                {
                    left += dp[i][j - 1];
                }else left = INT_MAX;

                dp[i][j] = min(up, left);
            }          
        }
    }

    return dp[n -1][m-1];
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
}