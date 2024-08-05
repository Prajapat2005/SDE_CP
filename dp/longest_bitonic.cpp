#include <bits/stdc++.h>
using namespace std;

vector<int> increase(vector<int> v, int n)
{

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int pre = 0; pre <= i - 1; pre++)
        {

            if (v[i] > v[pre])
            {
                dp[i] = max(dp[pre] + 1, dp[i]);
            }
        }
    }
    return dp;
}
vector<int> decrease(vector<int> v, int n)
{

    vector<int> dp(n, 1);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int pre = n - 1; pre >= i + 1; pre--)
        {

            if (v[i] > v[pre])
            {
                dp[i] = max(dp[pre] + 1, dp[i]);
            }
        }
    }
    return dp;
}
int LongestBitonicSequence(int n, vector<int> &nums)
{

    vector<int> dp1 = increase(nums, n);
    vector<int> dp2 = decrease(nums, n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        /* if (dp1[i] == 1 || dp2[i] == 1) if we consider A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence
            continue; */
        ans = max(ans, abs(dp1[i] + dp2[i]) - 1);
    }

    return ans;
}