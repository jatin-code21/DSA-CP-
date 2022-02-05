#include <bits/stdc++.h>
using namespace std;

vector<string> Lcp(string ip, string op, vector<string> &allop)
{
    // vector for storing all the possible output which will also include duplicates;
    if (ip.length() == 0)
    {
        allop.push_back(op);
        return allop;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(tolower(ip[0]));
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin() + 0);
    Lcp(ip, op1, allop);
    Lcp(ip, op2, allop);
    return allop;
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
    vector<string> allop;
    set<string> st; // created set so that it will automatically remove the duplicates, one can do using another vector also;
    auto ans = Lcp(ip, op, allop);

    for (auto &it : ans)
    {
        st.insert(it);
    }
    for (auto &it : st)
    {
        cout << it << " ";
    }
}

// This one can be solved without using set or 2 vector also;