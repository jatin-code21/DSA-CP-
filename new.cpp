#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
const int mod = 1e9 + 7;
const double pie = 3.14159265;
using ll = long long;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
    cout.tie(NULL);
#define all(v) v.begin(), v.end()
#define allg(v) v.rbegin(), v.rend()
#define pb push_back
#define eb emplace_back
#define po pop_back
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define yes cout << "YES" \
                 << "\n"
#define no cout << "NO" \
                << "\n"
#define yesr           \
    {                  \
        cout << "YES"; \
        return;        \
    }
#define nor           \
    {                 \
        cout << "NO"; \
        return;       \
    }
#define inpvec        \
    ll n;             \
    cin >> n;         \
    vector<ll> v(n);  \
    for (auto &i : v) \
        cin >> i;
#define print(v)          \
    for (auto i : v)      \
    {                     \
        cout << i << " "; \
    }                     \
    cout << "\n";
#define inpstr \
    ll n;      \
    cin >> n;  \
    string s;  \
    cin >> s;
bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
ll largePow(ll a, ll b)
{
    ll anss = 1;
    while (b > 0)
    {
        if ((b & 1) != 0) // checking if b is odd or even
        {
            // this condition is for if b is ODD
            anss = (anss * (a % mod)) % mod;
        }
        // if b is EVEN
        a = (a % mod) * (a % mod);
        b = b >> 1; // just doing half of b, we can write b/2 also
    }
    return anss;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
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
ll Mex(unordered_set<ll> &st)
{
    ll mex = 0;

    while (st.find(mex) != st.end())
    {
        mex++;
    }
    return mex;
}
ll getIthbit(ll n, ll i)
{
    ll mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}
void setIthBit(ll &n, ll i)
{
    ll mask = (1 << i);
    n = (n | mask);
}
bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++)
    {
        if (S[i] != S[S.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}
bool areDistinct(vector<ll> arr)
{
    ll n = arr.size();
    unordered_set<int> s;
    for (ll i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    return (s.size() == arr.size());
}
ll highestPowerof2(unsigned int n)
{
    // Invalid input
    if (n < 1)
        return 0;

    ll res = 1;

    // Try all powers starting from 2^1
    for (ll i = 0; i < 8 * sizeof(unsigned int); i++)
    {
        ll curr = 1 << i;

        // If current power is more than n, break
        if (curr > n)
            break;

        res = curr;
    }

    return res;
}
string toBinary(ll n)
{
    string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}
ll binaryExponential(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m; // if the bit is set then only multiplying to the result
        a = (a * a) % m;         // squaring the a
        b = (b >> 1) % m;        // removing the last bit
    }
    return res;
}
vector<ll> factors(ll n)
{
    vector<ll> facts;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            facts.pb(i);
            if (i != n / i)
            {
                facts.pb(n / i);
            }
        }
    }
    return facts;
}
ll mul(ll a, ll b)
{
    return (a % mod * b % mod) % mod;
}

ll mod_inverse(ll a, ll mod)
{
    return binaryExponential(a, mod - 2, mod);
}
const int N = 2e5 + 1;
vector<ll> fact(N), invfact(N);
void pre()
{
    fact[0] = invfact[0] = 1;
    rep(i, 1, N)
    {
        fact[i] = mul(fact[i - 1], i);
        invfact[i] = mul(invfact[i - 1], mod_inverse(i, mod));
    }
}
//********************************************************************************
bool isSafe(vector<vector<ll>> &v, ll n, ll m, ll i, ll j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return true;
    }
    return false;
}
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// min cost to react from first row cell to any last row cell
ll minCost(vector<vector<ll>> &v, ll n, ll m, ll i, ll j)
{
    if (i == n - 1)
    {
        // ans = min(ans, cost);
        // return;
        return 0;
    }
    int min_cost = INT_MAX;
    for (const pair<int, int> &dir : directions)
    {
        int newRow = i + dir.first;
        int newCol = j + dir.second;

        // Check if the new position is within bounds
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
        {
            // Calculate the cost to move to the new cell
            int cost = abs(v[i][j] - v[newRow][newCol]) + minCost(v, n,m, newRow, newCol);

            // Update the minimum cost
            min_cost = min(min_cost, cost);
        }
    }
    return min_cost;
    // if (isSafe(v, n, m, i + 1, j))
    // {
    //     minCost(v, n, m, i + 1, j, ans, cost + abs(v[i][j] - v[i + 1][j]));
    // }
    // if (isSafe(v, n, m, i, j - 1))
    // {
    //     minCost(v, n, m, i + 1, j - 1, ans, cost + abs(v[i][j] - v[i][j - 1]));
    // }
    // if (isSafe(v, n, m, i, j + 1))
    // {
    //     minCost(v, n, m, i + 1, j + 1, ans, cost + abs(v[i][j] - v[i][j + 1]));
    // }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> v[i][j];
        }
    }
    ll ans = INT_MAX, cost = 0;
    rep(i, 0, n)
    {
        ans = min(ans, minCost(v, n, m, 0, i));
    }
    cout << ans << nline;
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}