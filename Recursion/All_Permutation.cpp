#include <bits/stdc++.h>
using namespace std;

void allPermutation(int ind, vector<int> &a, vector<vector<int>> &ans)
{
    if (ind == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = ind; i < a.size(); i++)
    {
        swap(a[ind], a[i]);
        allPermutation(ind + 1, a, ans);
        swap(a[ind], a[i]); // reswapping backtracking case simple
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> ans;
    allPermutation(0, a, ans);
}