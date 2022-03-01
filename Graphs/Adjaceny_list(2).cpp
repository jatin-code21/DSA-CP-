// In this method we create the n number of list where n is number of vertices and in respective list we store the vertex number to which it is connected;

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<pair<int, int>> graph[N];
// so here basically graph[0] will tell us the the 0 is connected to which which vertices;
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt; // edge is connected by what weight;
        graph[v1].push_back({v2, wt});
        graph[v2].push_back({v1, wt});
    }
}

// Space complexity is O(n + m);