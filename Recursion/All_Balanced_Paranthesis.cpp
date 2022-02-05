#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, string op, vector<string> &v)
{
    if (open == 0 && close == 0)
    {
        v.push_back(op);
        return;
    }
    if (open != 0)
    {
        string op1 = op;
        op1.push_back('(');

        solve(open - 1, close, op1, v);
    }
    if (close > open)
    {
        string op2 = op;
        op2.push_back(')');
        solve(open, close - 1, op2, v);
    }
    return;
}

vector<string> abp(int n)
{
    vector<string> v;
    int open = n, close = n;
    string op = "";
    solve(open, close, op, v);
    return v;
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
    auto ans = abp(n);
    for (auto &i : ans)
    {
        cout << i << " ";
    }
}