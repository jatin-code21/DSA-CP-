#include <bits/stdc++.h>
using namespace std;

void subSet(string inp, string outp)
{
    if (inp.length() == 0)
    {
        cout << outp << " ";
        return;
    }
    string op1 = outp;
    string op2 = outp;
    op2.push_back(inp[0]);
    inp.erase(inp.begin() + 0);
    subSet(inp, op1);
    subSet(inp, op2);
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    string inp;
    cin >> inp;
    string outp = "";
    subSet(inp, outp);
}