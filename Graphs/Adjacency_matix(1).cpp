// To represent graph in code form we have 2 methods: 1-> Adjacency Matrix 2-> Adjacency List
// 1st Method: Acc to this create a N*N matrix where N is no. of vertex in a Graph and mark matrix[i][j] = 1 if there exists a edge between them else mark 0;

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int graph[N][N]; // as this is global variable so automatically all values will be initialized by 0;

int main()
{
    int n, m; // n is vertex and m is edges;
    cin >> n >> m;
    // int graph[n + 1][n + 1]; // one base indexing;
    while (m--)
    {
        int v1, v2;
        cin >> v1 >> v2; // vertex betn which edges exists;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}

// Space Complexity is O(N*N);
// also if we N is suppose 10e5 then also we cant store the graph in such a way because the max continuous allocation of array can 10e7-10e8;