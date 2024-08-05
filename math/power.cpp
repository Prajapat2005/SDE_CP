#include <bits/stdc++.h>
using namespace std;
// O(log(n));
int power(int n, int m)
{
    if (m == 1)
        return n;
    if (m == 0)
        return 1;
    if (m % 2 == 0)
        return power(n, m / 2) * power(n, m / 2);
    else
        return power(n, m / 2) * power(n, (m + 1) / 2);
}

int power(int n, int m, int mod)
{
    if (m == 1)
        return n;
    if (m == 0)
        return 1;
    if (m % 2 == 0)
        return ((power(n, m / 2, mod) % mod) * (power(n, m / 2, mod) % mod)) % mod;
    else
        return ((power(n, m / 2, mod) % mod) * (power(n, (m + 1) / 2, mod) % mod)) % mod;
}

// O(log(n)) base 2
double myPow(double x, long long n)
{

    double ans = 1.0;
    long long p = n;
    if (n < 0)
        p = p * (-1);
    while (p)
    {
        if (p % 2 == 0)
        {
            x = x * x;
            p = p / 2;
        }
        else
        {
            ans = ans * x;
            p = p - 1;
        }
    }
    if (n < 0)
        return 1.00000 / ans;
    else
        return ans;
}

int main()
{
    cout << power(5, 4);
    return 0;
}
