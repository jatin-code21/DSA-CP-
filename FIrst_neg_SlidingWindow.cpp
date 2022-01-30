#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < k - 1; i++)
        {
            if (arr[i] < 0)
                q.push(arr[i]);
        }
        for (int i = k - 1; i < n; i++)
        {
            if (arr[i] < 0)
                q.push(arr[i]);
            if (!q.empty())
            {
                ans.push_back(q.front());
                if (q.front() == arr[i - k + 1])
                {
                    q.pop();
                }
            }
            else
            {
                ans.push_back(0);
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}