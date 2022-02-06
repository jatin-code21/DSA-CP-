#include <bits/stdc++.h>
using namespace std;

void Josephus(vector<int> &v, int k, int index, int &ans)
{
    if (v.size() == 1) // Base conditon
    {
        ans = v[0];
        return;
    }
    index = (index + k) % v.size(); // index is basically the starting person/position from where the new counting will start after the last person/element is dead/removed;
    v.erase(v.begin() + index);
    Josephus(v, k, index, ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n, k; // total number of people in circle and k is counting from himself the kth number person will die;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    k--;           // as he is staring counting by himself so we actually need -> +(k - 1)th person;
    int index = 0; // staring is from first person/element;
    int ans = -1;  // this will give us the final answer i.e the last person left;
    Josephus(v, k, index, ans);
    cout << ans;
}