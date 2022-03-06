#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int parent)
{
    vis[vertex] = true;
    bool isLoopExist = false;
    for (int child : g[vertex])
    {
        if (vis[child] && child == parent)
            continue;
        if (vis[child])
            return true;
        isLoopExist |= dfs(child, vertex); // applying or condition because any one of the child is forming loop then overall the cycle exists;
    }
    return isLoopExist;
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
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1); // indicating its undirected graph;
    }
    bool isLoopExist = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (dfs(i, 0)) // 0 because first i = 1 is not connected to anyone so we are passing 0 as the parent of it;
        {
            isLoopExist = true;
            break;
        }
    }
    cout << isLoopExist << "\n";
}