#include <bits/stdc++.h>
using namespace std;
int ans(vector<int> v, int i, int j, vector<vector<int>> &dp)
{

    if (i > j)
        return 0;
    int mini = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        if (dp[i][k - 1] == -1)
            dp[i][k - 1] = ans(v, i, k - 1, dp);
        if (dp[k + 1][j] == -1)
            dp[k + 1][j] = ans(v, k + 1, j, dp);

        int step = v[j + 1] - v[i - 1] + dp[i][k - 1] + dp[k + 1][j];
        mini = min(step, mini);
    }

    return mini;
}
int ans2(vector<int> v)
{

    int n = v.size();
    vector<vector<int>> dp(v.size() + 1, vector<int>(v.size() + 1, 0));
    int mini = INT_MAX;
    for (int i = n - 2; i >= 1; i--)
    {
        for (int j = n - 2; j >= i; j--)
        {
            for (int k = i; k <= j; k++)
            {
                mini = min(mini, v[j + 1] - v[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
            }
            dp[i][j] = mini;
        }
    }

    return mini;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i];

    v.insert(v.begin(), 0);
    v.push_back(n);

    sort(v.begin(), v.end());

    cout << ans2(v);
}
