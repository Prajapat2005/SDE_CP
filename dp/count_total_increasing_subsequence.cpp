#include <bits/stdc++.h>
using namespace std;

int ans1(vector<int> v, int n)
{

    vector<int> dp(n, 1);    // dp[i] is max length of increasing subsequence upto i
    vector<int> count(n, 1); // count[i] is total number of max length increasing subsequence upto i
    int maxi = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int pre = 0; pre <= i - 1; pre++)
        {

            if (v[i] > v[pre])
            {
                if (dp[pre] + 1 > dp[i])
                {
                    dp[i] = dp[pre] + 1;
                    count[i] = count[pre];
                }
                else if (dp[pre] + 1 == dp[i])
                {
                    count[i] += count[pre];
                }
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }

    int x = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            x = x + count[i];
    }

    return x;
}
int findNumberOfLIS(vector<int> &v)
{

    if (v.size() == 1)
        return 1;

    return ans1(v, v.size());
}