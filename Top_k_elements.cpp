#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // creation of min heap 
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (auto i: mp)
    {
        pq.push({i.second, i.first});
        if (pq.size() > k) pq.pop();
    }
    while (pq.size())
    {
        cout << pq.top().second << " ";
        pq.pop();
    }
}
