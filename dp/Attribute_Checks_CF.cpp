/*https://codeforces.com/contest/2025/problem/D*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int n, int m)
{

    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
    int t = 0;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            v1.push_back(-v[i]);
        }
        else if (v[i] > 0)
        {
            v2.push_back(v[i]);
        }
        else
        {
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            t++;
            for (int j = 0; j <= t; j++)
            {

                if (j != 0)
                {
                    int val1 = upper_bound(v1.begin(), v1.end(), j - 1) - v1.begin();
                    // prev zero st-->j-1 and int--->t-j curr st liya h
                    int val2 = upper_bound(v2.begin(), v2.end(), t - j) - v2.begin();
                    dp[t][j] = max(dp[t][j], dp[t - 1][j - 1] + val1 + val2);
                }

                if (j < t)
                {
                    int val1 = upper_bound(v1.begin(), v1.end(), j) - v1.begin();
                    // prev zero st-->j and int--->t-j-1 curr int liya h
                    int val2 = upper_bound(v2.begin(), v2.end(), t - j - 1) - v2.begin();
                    dp[t][j] = max(dp[t][j], dp[t - 1][j] + val1 + val2);
                }
            }
            v1.clear();
            v2.clear();
        }
    }
    int ans = 0;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int j = 0; j <= m; j++)
    {
        int val1 = upper_bound(v1.begin(), v1.end(), j) - v1.begin();
        int val2 = upper_bound(v2.begin(), v2.end(), m - j) - v2.begin();
        ans = max(ans, dp[m][j] + val1 + val2);
    }

    return ans;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << solve(v, n, m);

    return 0;
}