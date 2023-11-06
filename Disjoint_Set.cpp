#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0); // rank is the height of the tree
        parent.resize(n + 1);  // using the one based indexing
        size.resize(n + 1, 1); // size is the number of nodes in the tree
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltiParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltiParent(parent[node]);
        // this is the path compression
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUltiParent(u);
        int ulp_v = findUltiParent(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUltiParent(u);
        int ulp_v = findUltiParent(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // If 3 and 7 are in same component or not
    if (ds.findUltiParent(3) == ds.findUltiParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }
    ds.unionByRank(3, 7);
    // After connecting 3 and 7
    if (ds.findUltiParent(3) == ds.findUltiParent(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }
}