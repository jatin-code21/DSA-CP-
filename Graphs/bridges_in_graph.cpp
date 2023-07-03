#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<pair<int, int>> &bridges)
{
    vis[node] = true;
    tin[node] = low[node] = timer++;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        if (vis[child])
        {
            // back edge
            low[node] = min(low[node], tin[child]);
        }
        else
        {
            // forward edge
            dfs(child, node, vis, adj, tin, low, bridges);
            if (low[child] > tin[node])
            {
                bridges.push_back({node, child});
            }
            low[node] = min(low[node], low[child]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(n, -1), low(n, -1); // tin -> time of insertion, low -> lowest time of insertion of a node reachable from current node
    vector<bool> vis(n, false);
    vector<pair<int, int>> bridges;
    dfs(0, -1, vis, adj, tin, low, bridges);
    for (auto it : bridges)
    {
        cout << it.first << " " << it.second << "\n";
    }
}

// Space Complexity : O(V + 2E) + O(3N)
// Time Complexity : O(V + 2E)