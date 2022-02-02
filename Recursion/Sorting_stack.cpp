#include <bits/stdc++.h>
using namespace std;

void Insertion(stack<int> &stk, int temp)
{
    if (stk.size() == 0 || stk.top() <= temp)
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

void SortStack(stack<int> &stk)
{
    if (stk.size() == 1)
        return;
    int temp = stk.top();
    stk.pop();
    SortStack(stk);
    Insertion(stk, temp);
}

int main()
{
    stack<int> stk;
    stk.push(4);
    stk.push(1);
    stk.push(2);
    stk.push(9);
    stk.push(3);
    SortStack(stk);
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}