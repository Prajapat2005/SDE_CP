#include <bits/stdc++.h>
using namespace std;

// time O(sqrt(n)*log(n))
void prime_factors(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n = n / i;
            }
            cout << i << "^" << count << " ";
        }
    }
    if (n > 1)
        cout << n << "^" << 1 << " ";
}
int main()
{
    prime_factors(20);
    return 0;
}
// 2^2 5^1