#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<bool> &vis, vector<int> adjT[]) // for printing the strongly connected components i.e for reversed graph
{
    vis[node] = true;
    // cout << node << " ";
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs2(it, vis, adjT);
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
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> adjT[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    vector<bool> vis(n,false);
    stack<int> st; // for storing the vertices in order of their finish time
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,st);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) vis[i] = false;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cnt++;
            dfs2(node, vis, adjT);
            // cout << endl;
        }
    }
    cout << cnt << endl;
}

// Time complexity: O(3(V+E))
// Space complexity: O(V+E) + O(V) + O(V) + O(V) = O(V+E)
// Some important points:

// 1. sort the vertices in order of their finish time
// 2. reverse the graph
// 3. do dfs on the reversed graph in order of their finish time

// This is called as Kosaraju's algorithm