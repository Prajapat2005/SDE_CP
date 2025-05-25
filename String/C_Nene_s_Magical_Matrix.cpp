#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    return;
}
void funr(int n)
{
    for (int i = n; i >= 1; i--)
    {
        cout << i << " ";
    }
    return;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int sum = 0;

        for (int i = n; i > 1; i--)
        {
            sum += (i * (2 * i - 1));
        }

        sum++;

        cout << sum << " " << 2 * n << "\n";

        for (int i = n; i >= 1; i--)
        {
            cout << 1 << " " << i << " ";
            fun(n);
            cout << "\n";
            cout << 2 << " " << i << " ";
            fun(n);
            cout << "\n";
        }
    }
}