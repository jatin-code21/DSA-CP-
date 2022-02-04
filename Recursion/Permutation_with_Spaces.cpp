#include <bits/stdc++.h>
using namespace std;

void Pws(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << " ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op1 += " ";
    op1.push_back(ip[0]); // above 2 lines is adding B with space
    op2.push_back(ip[0]); // adding B without space as we have 2 choices(decision);
    ip.erase(ip.begin() + 0);
    Pws(ip, op1);
    Pws(ip, op2);
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
    op.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    Pws(ip, op);
}