#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    // here i,j will represent that if you consider the i no. of char and j no. of char of other string then what will be the length of the increasing common subsequence
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int opt1 = dp[i - 1][j];
                int opt2 = dp[i][j - 1];
                dp[i][j] = max(opt1, opt2);
            }
        }
    }
    return dp[n1][n2];

    vector<char> result;
    int i = n1, j = n2;
    while (i != 0 && j !=0)
    {
        if (dp[i][j] == dp[i][j - 1]){
            j--; 
            // moving in a max direction
        }
        else if (dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else
        {
            // moving diagonally because we know that it must been equal therfore its value is increase;
            result.push_back(s1[i -1]);
            i--;
            j--;
        }
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1,s2);
}