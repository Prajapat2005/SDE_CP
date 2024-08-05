#include <bits/stdc++.h>
using namespace std;

// n(log(log(n)))
void Sieve(int n)
{
    vector<int> v(n + 1, -1);
    v[0] = v[1] = -1;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j = j + i)
        {
            if (v[j] == -1)
                v[j] = i; // here we store smallest prime multiple of that no
        }
    }

    while (n)
    {
        if (v[n] != -1)
        {
            cout << v[n] << "*";
            n = n / v[n];
        }
        else
        {
            cout << n << "*";
            break;
        }
    }
}
int main()
{
    Sieve(20);
    return 0;
}