#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int m, n, source;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    // vector<int> vis(n +1, 0);
    vector<int> dist(n + 1, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    cin >> source;
    dist[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int child : g[cur])
        {
            if (dist[child] == INT_MAX)
            {
                dist[child] = dist[cur] + 1;
                q.push(child);
            }
        }
    }
}