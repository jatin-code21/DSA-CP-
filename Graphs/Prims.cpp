#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    vector<int> parent(n, -1);
    vector<bool> vis(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // {wt, node}
    int cost = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node])
        {
            continue;
        }
        vis[node] = true;
        cost += wt;
        for (auto child : adj[node])
        {
            if (!vis[child.first])
            {
                pq.push({child.second, child.first});
            }
        }
    }
}