#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];         // tells whether the vertex is visited or not
void dfs(int vertex) // from which vertex we have to start dfs
{
    // Take action on vertex after entering the vertex;

    // if (vis[vertex]) return; -> in place of line 14 we can write this also;
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        if (vis[child])
            continue;
        // take action on child before entering the child node

        dfs(child);

        // take action on child after exiting the child node
    }
    // Take action on after exiting the vertex
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1); // indicating that its undirected graph
    }
}