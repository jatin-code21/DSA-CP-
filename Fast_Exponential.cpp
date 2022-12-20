// Calculate a^b in O(logb) time, and O(1) space
// representing the b in binary form and wherever the bit is set that have to be multiplied with the a.
// Example: 3^5 -> 5 in base 2 is 101 so 3^1 * 3^2 * 3^3 but only 1st and 3rd bit is set so 3^1 * 3^3 will be answer (in case of odd power multiply with extra a one time at the end);

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fastExponential(ll a, ll b, ll m)
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

int main()
{
    ll a, b, m;
    cin >> a >> b >> m;
    cout << fastExponential(a, b, m) << endl;
    return 0;
}