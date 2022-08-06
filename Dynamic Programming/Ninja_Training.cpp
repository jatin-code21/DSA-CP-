#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;

int maxPoints(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int mx = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                mx = max(mx, points[0][task]);
            }
        }
        return mx;
    }
    if (dp[day][last] != -1) return dp[day][last];

    int mx = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + maxPoints(day-1, task, points, dp);
            mx = max(mx, point);
        }
    }
    return dp[day][last] = mx;
}

// Time Complexity of Recursion + Memoization -> O(n*4)*3;
// Space Complexity -> O(n) + O(n*4);


int maxPointsTabulation(vector<vector<int>> &points, vector<vector<int>> &dp)
{
    int n = dp.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            dp[i][j] = 0;
        }
    }
    // Above step is just initializing the dp vector with 0 you can do it directly while decalaring the vector;

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];

                    dp[day][last] = max(dp[day][last],point); 
                }
            }
        }
    }

    return dp[n - 1][3];
}
// Time Complexity -> O(n*4*3);
// Space Complexity -> O(n*4);

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(4, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    cout << maxPoints(n-1, 3, points, dp) << "\n";
}