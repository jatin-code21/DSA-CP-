// Print all the subsequences whose sum is equal to target value. the element may be repeated.

#include <bits/stdc++.h>
using namespace std;

void findCombination(vector<int> &a, int target, int ind, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == a.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (a[ind] <= target)
    {
        ds.push_back(a[ind]);
        findCombination(a, target - a[ind], ind, ans, ds);
        ds.pop_back();
    }
    findCombination(a, target, ind + 1, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &a, int target)
{
    vector<vector<int>> ans;
    vector<int> ds; // data structure to store the value of different subsequences whose sum is equal ot k;
    findCombination(a, target, 0, ans, ds);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto combs = combinationSum(a, target);
    for (int i = 0; i < combs.size(); i++)
    {
        for (int j = 0; j < combs[i].size(); j++)
        {
            cout << combs[i][j] << " ";
        }
        cout << "\n";
    }
}