#include <bits/stdc++.h>
using namespace std;

void Insertion(stack<int> &stk, int temp)
{
    if (stk.size() == 0)
    {
        stk.push(temp);
        return;
    }
    int val = stk.top();
    stk.pop();
    Insertion(stk, temp);
    stk.push(val);
    return;
}

void reverseStack(stack<int> &stk)
{
    if (stk.size() == 1)
        return;
    int temp = stk.top();
    stk.pop();
    reverseStack(stk);
    Insertion(stk, temp);
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
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    int k = (stk.size() / 2) + 1; // mid element from the top;
    reverseStack(stk);
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}