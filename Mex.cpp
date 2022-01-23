#include <bits/stdc++.h>
using namespace std;

// In set the smallest non-negative Integer which is not present is called MEX;
int Mex(unordered_set<int> &st)
{
    int mex = 0;

    while (st.find(mex) != st.end())
    {
        mex++;
    }
    return mex;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }

    cout << Mex(st);
}