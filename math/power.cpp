#include <bits/stdc++.h>
using namespace std;
// O(log(n));
int power(int n, int m, int mod)
{
    if (m == 1)
        return n;
    if (m == 0)
        return 1;

    int x = power(n, m / 2, mod);

    x = (x * x) % mod;
    if (m % 2 != 0)
    {
        x = (x * n) % mod;
    }

    return x;
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
