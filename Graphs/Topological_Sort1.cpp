// The concept of Topological sort is that to print the nodes in the format which are less dependent on other nodes i.e the indegree of which node is less will be printed first.
// This is also called as Kahn's Algorithm.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> indegree(n, 0);
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        auto data = adj[i];
        for (auto x : data)
        {
            indegree[x]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for (auto child: adj[x])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
}