#include <bits/stdc++.h>
using namespace std;

int HexaToDeci(string s)
{
    int n = s.length();
    int base = 1; // for unit place we multiply by 16^0 == 1
    int deci_num = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9') // here if char is an integer betn 0 - 9 we convert it to integer
        {
            deci_num += (int(s[i] - 48)) * base;

            base *= 16; // for tens place and so we need to update the base value i.e 16^1 = 16, 16^2...;
        }
        else if (s[i] >= 'A' && s[i] <= 'F') // here if char is betn A and F we convert it into their respective integer equivalent
        {
            deci_num += (int(s[i] - 55)) * base;

            base *= 16;
        }
    }
    return deci_num;
}

int main()
{
    string s; // input of a hexadecimal number as a string
    cin >> s;
    cout << HexaToDeci(s);
}