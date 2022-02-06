// Printing N digit binary number with #1 >= #0;
#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int one, int zero, int n, string op, vector<string> &v)
{
    // vector<string> v;
    if (n == 0)
    {
        v.push_back(op);
        return v;
    }
    string op1 = op;
    op1.push_back('1');
    solve(one + 1, zero, n - 1, op1, v);
    if (one > zero)
    {
        string op2 = op;
        op2.push_back('0');
        solve(one, zero + 1, n, op2, v);
    }
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
    string op = "";
    int one = 0, zero = 0;
    vector<string> v;
    auto ans = solve(one, zero, n, op, v);
    for (auto &i : ans)
    {
        cout << i << " ";
    }
}