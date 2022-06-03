// print the sum of all possible subset in sorted order

#include <bits/stdc++.h>
using namespace std;

void subsetSum(int ind, vector<int> &v, int sum, vector<int> &ans)
{
    if (ind == v.size())
    {
        ans.push_back(sum);
        return;
    }
    subsetSum(ind + 1, v, sum + v[ind], ans); // when the element from the set is picked
    subsetSum(ind + 1, v, sum, ans);          // when the element from the set is not picked
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
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int sum = 0;
    vector<int> ans;
    subsetSum(0, v, sum, ans);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

// Time Complexity -> O(2^n*(2^n)log(2^n)); the extra T.C is due to sorting;
// Space Complexity -> O(2^n); because the total number of subsets possible will have 2^n possible sum values;