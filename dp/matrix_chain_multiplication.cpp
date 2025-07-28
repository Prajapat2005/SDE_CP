#include <bits/stdc++.h>
using namespace std;
int MCM(vector<int> v, int i, int j)
{

    if (i == j)
        return 0;
    int mini = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int step = v[i - 1] * v[k] * v[j] + MCM(v, i, k) + MCM(v, k + 1, j);
        mini = min(mini, step);
    }

    return mini;
}

int MCM_dp(vector<int> v, vector<vector<int>> dp, int i, int j)
{

    for (int p = 0; p < v.size(); p++)
        dp[p][p] = 0;
    int mini = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        if (dp[i][k] == -1)
            dp[i][k] = MCM_dp(v, dp, i, k);
        if (dp[k + 1][j] == -1)
            dp[k + 1][j] = MCM_dp(v, dp, k + 1, j);

        int step = v[i - 1] * v[k] * v[j] + dp[i][k] + dp[k + 1][j];

        mini = min(mini, step);
    }

    return mini;
}

// tabulation
int MCM_dp_1(vector<int> v, vector<vector<int>> dp)
{

    int n = v.size();
    for (int p = 1; p < v.size(); p++)
        dp[p][p] = 0; // base case i==j return 0;

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            int mini = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {

                int step = v[i - 1] * v[k] * v[j] + dp[i][k] + dp[k + 1][j];

                mini = min(mini, step);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][v.size() - 1];
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << MCM_dp_1(v, dp);
    return 0;
}