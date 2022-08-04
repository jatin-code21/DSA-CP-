#include <bits/stdc++.h>
using namespace std;

bool compareBoxes(vector<int> b1, vector<int> b2)
{
    return b1[2] > b2[2];
}

bool canPlace (vector<int> b1, vector<int> b2)
{
    if (b1[0] > b2[0] && b1[1] > b2[1] && b1[2] > b2[2])
    {
        return true;
    }
    return false;
}

int boxStacking(vector<vector<int>> &boxes)
{
    int n = boxes.size();
    // sorting according to the heights of the boxes
    sort(boxes.begin(), boxes.end(), compareBoxes);

    vector<int> dp(n + 1, 0);
    
    for (int i = 0; i < n; i++)
    {
        dp[i] = boxes[i][2];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (canPlace(boxes[j], boxes[i])) // box[j] ko box[i] ke upar rakh skte kya
            {
                int cur_height = boxes[i][2];
                if (dp[j] + cur_height > dp[i])
                {
                    dp[i] = dp[j] + cur_height;
                }
            }
        }
    }
    int maxHeight = *max_element(dp.begin(), dp.end());
    return maxHeight;
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
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    auto maxHeight = boxStacking(v);
    cout << maxHeight << "\n";
}