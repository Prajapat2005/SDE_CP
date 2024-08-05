#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }

    if (dividend == divisor)
        return 1;

    long long ans = 0;
    int sign = 1;

    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        sign = -1;

    long long n = abs((long long)dividend), d = abs((long long)divisor);

    while (n >= d)
    {
        long long count = 0;
        while (n > (d << (count + 1)))
            count++;
        n -= d << count;
        ans += 1 << count;
    }

    if (ans == (1 << 31) && sign == 1)
        return INT_MAX;

    return sign * ans;
}