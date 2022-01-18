#include <bits/stdc++.h>
using namespace std;

int cnt_set_bit(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        if (n & 1 == 1)
            cnt++;
        n >>= 1; // here we are doing the right shift by which last digit is deleted;
    }
    return cnt;
    // Time Complexity -> O(log n)
}

int brian_kerninghan(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        n = n & (n - 1); // so in one loop this will unset one bit so the loop will continue until the all one's are unset
        cnt++;
    }
    return cnt;
    // Time Complexity -> O(number of set bits present);
}

int main()
{
    int n;
    cin >> n;
    cout << cnt_set_bit(n) << " ";
    cout << brian_kerninghan(n) << " ";
    cout << __builtin_popcount(n); // This is Built_in function available to count set bits..
}