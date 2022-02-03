#include <bits/stdc++.h>
using namespace std;

void DeleteMid(stack<int> &stk, int k)
{
    if (k == 1)
    {
        stk.pop();
        return;
    }
    int temp = stk.top();
    stk.pop();
    DeleteMid(stk, k - 1); // because as one element is pop out from top so the middle element which we wanna delete is at position (k - 1) from top;
    stk.push(temp);
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
    DeleteMid(stk, k);
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}