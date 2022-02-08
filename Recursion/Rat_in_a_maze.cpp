#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratinMaze(vector<vector<int>> &arr, int x, int y, int n, vector<vector<int>> &ans)
{
    if ((x == (n - 1)) && (y == (n - 1)))
    {
        ans[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n))
    {
        ans[x][y] = 1;

        if (ratinMaze(arr, x + 1, y, n, ans)) // checking if it possible to go down
        {
            return true;
        }
        if (ratinMaze(arr, x, y + 1, n, ans)) // if not possible to go down checking if it can go to right
        {
            return true;
        }

        ans[x][y] = 0; // BACKTRACKING
        return false;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) // where the rat can go or not; 1 means it can go else not
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = 0;
        }
    }

    if (ratinMaze(arr, 0, 0, n, ans))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
}