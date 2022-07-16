#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - coins[i] >= 0)
            {

                dp[j] = (dp[j - coins[i]] % mod + dp[j] % mod) % mod;
            }
        }
    }
    cout << dp[x] % mod;
}

// In normal Coin Combination question we have to find the total number of ways i.e the permutation of coins are also possible asnwer
// but in this we just have to find the Combination i.e unique way to find the desired sum
// So instead of breaking x into different part the coins are repeated so here we think of reverse/opposite approach
// i.e first here we will find that with the help of given coin which which x(desired sum) can be achieved by which we will get only unique ways/combination to achieve a sum x;