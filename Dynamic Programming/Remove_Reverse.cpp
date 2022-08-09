#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto &i : s)
    {
        mp[i]++;
    }
    int i = 0, j = s.size() - 1;
    int leftInt = 0, rightInt = s.size() - 1;
    int flag = 0;
    while (i < j)
    {
        if (!flag)
        {
            if (mp[s[i]] > 1)
            {
                mp[s[i]]--;
                i++;
                leftInt = i;
                flag = 1;
            }else i++;
        }
        else
        {
            if (mp[s[j]] > 1)
            {
                mp[s[j]]--;
                j--;
                rightInt = j;
                flag = 0;
            }
            else j--;
        }
    }
    string ans;
    for (int i = leftInt; i <= rightInt; i++) ans += s[i];
    cout << ans << "\n";
}