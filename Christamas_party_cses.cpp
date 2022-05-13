#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 1;
int D[N];

int main()
{
    int n;
    cin >> n;
    D[0] = 0;
    D[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        D[i] = ((i - 1) * (D[i - 1] + D[i - 2])) % mod;
    }
    cout << D[n] << "\n";
}