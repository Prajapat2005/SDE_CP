#include <bits/stdc++.h>
using namespace std;

// T(sqrt(n))
vector<int> divisors(int n)
{

    vector<int> ans;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i)
            {
                ans.push_back(n / i);
            }
        }
    }

    return ans;
}

int main()
{

    vector<int> ans = divisors(36);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}