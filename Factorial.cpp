#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int mod = 1e9 + 7;
int fact[N];

void compute_factorial()
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

int main()
{
    compute_factorial();
    cout << fact[18];
}