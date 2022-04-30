#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

bool vis[1001][1001];
char br[1001][1001];
vector<char> path;
int n, m;

bool isValid(int x, int y, vector<vector<char>> &v)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;

    if (v[x][y] == '#' || vis[x][y] == true)
        return false;

    return true;
}

bool bfs(int x, int y, vector<vector<char>> &v)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (v[r][c] == 'B')
        {
            while (1)
            {
                path.push_back(br[r][c]);

                if (path.back() == 'L')
                    c++;
                if (path.back() == 'R')
                    c--;
                if (path.back() == 'U')
                    r++;
                if (path.back() == 'D')
                    r--;

                if (r == x && c == y)
                    break;
            }
            return true;
        }

        // left
        if (isValid(r, c - 1, v))
            br[r][c - 1] = 'L', q.push({r, c - 1}), vis[r][c - 1] = true;

        // right
        if (isValid(r, c + 1, v))
            br[r][c + 1] = 'R', q.push({r, c + 1}), vis[r][c + 1] = true;

        // up
        if (isValid(r - 1, c, v))
            br[r - 1][c] = 'U', q.push({r - 1, c}), vis[r - 1][c] = true;

        // down
        if (isValid(r + 1, c, v))
            br[r + 1][c] = 'D', q.push({r + 1, c}), vis[r + 1][c] = true;
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt",
    //             "r", stdin);
    //     freopen("output.txt",
    //             "w", stdout);
    // #endif
    cin >> n >> m;
    int x, y;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                x = i;
                y = j;
            }
        }
    }
    if (bfs(x, y, v))
    {
        cout << "YES" << nline << path.size() << nline;
        while (path.size() > 0)
        {
            cout << path.back();
            path.pop_back();
        }
    }
    else
        cout << "NO" << nline;
}