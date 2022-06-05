#include <bits/stdc++.h>
using namespace std;

void subsetSum(int ind, vector<int> &v, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < v.size(); i++)
    {
        if (i != ind && v[i] != v[i - 1])
        {
            ds.push_back(v[i]);
            subsetSum(i + 1, v, ds, ans);
            ds.pop_back();
        }
    }
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
    vector<int> ds;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    subsetSum(0, v, ds, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

// Time Complexity -> O(2^n*n)
// Space Complexity -> O(2^n) * O(k) where k is the avg length of each subset;
// Auxillary Space -> O(n) this is due to the recursion calls;