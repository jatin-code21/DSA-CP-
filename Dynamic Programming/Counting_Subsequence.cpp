#include <bits/stdc++.h>
using namespace std;

// Recursive
int countSub(string a, string b, int m, int n, vector<vector<int>> dp)
{
    if (m == -1 && n == -1 || n == -1) return 1;
    if (m == -1) return 0;

    if (a[m] == a[n])
    {
        return countSub(a,b,m-1,n-1, dp) + countSub(a,b,m - 1, n, dp);
    }
    return countSub(a,b,m-1, n, dp);
}

int countSubBU(string a, string b)
{
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1]==b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout << countSub(s1, s2, s1.size() - 1, s2.size() - 1, dp);
    cout << countSubBU(s1, s2) << "\n";
}