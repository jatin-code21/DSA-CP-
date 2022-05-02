#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int mod = 1e9 + 7;
int fact[N], invfact[N];
using ll = long long;

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll x = power(a, b / 2);
        return (x * x) % mod;
    }
    else
    {
        ll x = power(a, b / 2);
        ll ans = (x * x) % mod;
        return (ans * b) % mod; // because here one number will be remaining whose pair will not be formed;
    }
}

ll inverse(ll a)
{
    return (a, mod - 2); // fermets theorem;
}

ll nCr(ll n, ll r)
{
    if (n < 0 || r < 0 || r > n)
    {
        return 0;
    }
    ll num = fact[n];
    ll den = (invfact[r] * invfact[n - r]) % mod;
    return (num * den) % mod;
}

void compute_factorial()
{
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = inverse(fact[i]);
    }
}

int main()
{
    compute_factorial();
    cout << fact[18];
}