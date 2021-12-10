#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
typedef long long ll;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
    cout.tie(NULL);

vector<bool> seiveOfErasthones(ll n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i * i <= n; i++)
    {
        for (ll j = 2 * i; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }
    return isPrime;
}

int main()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        auto v = seiveOfErasthones(n);
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] == true)
                cnt++;
        }
        cout << cnt << nline;
    }
}