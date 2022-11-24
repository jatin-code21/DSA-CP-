#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> vis(1001, vector<int>(1001, 0));

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    if (vis[x][y] == 1)
        return false;
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    dfs(1,1);
}