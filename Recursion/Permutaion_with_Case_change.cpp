#include <bits/stdc++.h>
using namespace std;

void PwCaseChange(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << " ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    op2.push_back(ip[0] - 32);
    ip.erase(ip.begin() + 0);
    PwCaseChange(ip, op1);
    PwCaseChange(ip, op2);
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
    string ip;
    cin >> ip;
    string op = "";
    PwCaseChange(ip, op);
}