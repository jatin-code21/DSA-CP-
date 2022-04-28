#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int>> &g, int vertex, int n)
{
    vector<int> bfs;
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 1;
    while (!q.empty())
    {
        int fr = q.front();
        bfs.push_back(fr);
        q.pop();
        for (auto &i : g[fr])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return bfs;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int m, n, vertex;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    cin >> vertex;
    auto ans = BFS(g, vertex, n);
    for (auto &i : ans)
    {
        cout << i << " ";
    }
}