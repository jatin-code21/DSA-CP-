#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int largePow(int a, int b)
{
    int anss = 1;
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

int main()
{
    int a = 2, b = 3;
    cout << largePow(a, b);
}