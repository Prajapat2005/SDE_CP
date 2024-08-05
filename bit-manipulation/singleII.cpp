#include <bits/stdc++.h>
using namespace std;

int single(vector<int> v)
{

    vector<int> freq(32, 0);

    for (int i = 0; i < v.size(); i++)
    {

        int num = v[i];

        for (int i = 0; i < 32; i++)
        {
            if (num & (1 << i))
                freq[i]++;
        }
    }

    int ans = 0;
    int mul = 1;
    for (int i = 0; i < 32; i++)
    {

        if (freq[i] % 3 != 0)
        {
            ans = ans + mul;
        }
        mul = mul << 1;
    }

    return ans;
}
int main()
{
    cout << single({5, 5, 5, 6, 4, 4, 4});
}