#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(10001,vector<int>(10001,-1));
// In this i am making an upper diagonal matrix
// It can be made lower diagonal matrix also

int sumFreq(vector<int> &freq, int i, int j)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
    {
        sum += freq[k];
    }
    return sum;
}
int cost(int i, int j, vector<int> &freq)
{
    if (i > j) return 0;
    if (i == j) return dp[i][j] = freq[i];
    if (dp[i][j] != -1) return dp[i][j];

    int wt = sumFreq(freq, i, j);
    int mn_cost = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int temp = cost(i, k - 1, freq) + cost(k + 1, j, freq);
        mn_cost = min(temp, mn_cost);
    }
    return dp[i][j] = mn_cost + wt;
}

int main()
{
    int n;
    vector<int> keys(n,0);
    vector<int> freq(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> keys[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> freq[i];
    }
    int ans = cost(0,n-1,freq);
    cout << ans << "\n";
}