#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    int u, v, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : graph[node])
        {
            int edgewt = it.second;
            int adjnode = it.first;
            if (distance + edgewt < dist[adjnode])
            {
                dist[adjnode] = distance + edgewt;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
}

// Time Complexity: O(N + MlogM)
// Space Complexity: O(N + M)