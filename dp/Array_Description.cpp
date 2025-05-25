#include <bits/stdc++.h>
using namespace std;
#define int long long
//  https://cses.fi/problemset/task/1746
/* int solve(vector<int> v, int i, int &m)
{

    if (i == v.size())
    {
        return 1;
    }

    if (i - 1 >= 0 && v[i] != 0 && (abs(v[i] - v[i - 1]) > 1))
    {
        return 0;
    }
    else if (v[i] != 0)
    {
        return solve(v, i + 1, m);
    }

    if (i == 0)
    {
        int count = 0;
        for (int j = 1; j <= m; j++)
        {
            v[i] = j;
            count += solve(v, i + 1, m);
        }
        return count;
    }
    else
    {
        int count = 0;
        for (int j = max(1, v[i - 1] - 1); j <= min(m, v[i - 1] + 1); j++)
        {
            v[i] = j;
            count += solve(v, i + 1, m);
        }
        return count;
    }
} */

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 1));
    int mod = (1e9) + 7;

    // dp[i][v] = number of ways to fill the array up to index i, if x[i] = v

    if (v[0] == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }
    else
    {
        dp[0][v[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (v[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i - 1][j];
                if (j - 1 > 0)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j + 1 <= m)
                {
                    dp[i][j] += dp[i - 1][j + 1];
                }
                dp[i][j] %= mod;
            }
        }
        else
        {
            dp[i][v[i]] += dp[i - 1][v[i]];
            if (v[i] - 1 > 0)
            {
                dp[i][v[i]] += dp[i - 1][v[i] - 1];
            }
            if (v[i] + 1 <= m)
            {
                dp[i][v[i]] += dp[i - 1][v[i] + 1];
            }
            dp[i][v[i]] %= mod;
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        ans += dp[n - 1][i];
        ans %= mod;
    }

    cout << ans;
}