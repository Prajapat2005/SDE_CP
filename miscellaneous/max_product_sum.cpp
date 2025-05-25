#include <bits/stdc++.h>
using namespace std;
void solv()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int max = INT_MIN;
    int mul = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            mul = 1;
        else
        {
            mul = mul * v[i];
            if (mul > max)
                max = mul;
        }
    }
    mul = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] == 0)
            mul = 1;
        else
        {
            mul = mul * v[i];
            if (mul > max)
                max = mul;
        }
    }
    cout << max << endl;
}
int main()
{
    solv();
    return 0;
}