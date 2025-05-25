#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://cses.fi/problemset/task/1745

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j - v[i - 1] >= 0)
                dp[i][j] = dp[i][j] || dp[i - 1][j - v[i - 1]];
        }
    }

    vector<int> ans;

    for (int i = 1; i <= sum; i++)
    {
        if (dp[n][i])
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}