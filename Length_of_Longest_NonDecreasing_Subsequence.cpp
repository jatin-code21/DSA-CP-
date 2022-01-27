#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &a)
{
    vector<int> lis;
    for (auto &x : a)
    {
        auto it = upper_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
        {
            lis.push_back(x);
        }
        else
        {
            *it = x;
        }
    }
    return lis.size();
}

int main()
{
    vector<int> a = {2, 6, 5, 1, 4, 2};
    cout << LIS(a);
}