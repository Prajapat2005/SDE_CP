#include <iostream>
using namespace std;

// T(log(min(a,b)))
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
