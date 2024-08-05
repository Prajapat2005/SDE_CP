#include <bits/stdc++.h>
using namespace std;

int ans(vector<vector<int>> v, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
{

    if (j1 < 0 || j2 < 0 || j1 >= v[0].size() || j2 >= v[0].size())
    {
        return -1e9;
    }

    if (i == v.size() - 1)
    {
        if (j1 == j2)
            return v[i][j1];
        else
        {
            return (v[i][j1] + v[i][j2]);
        }
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;

    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {

            int l;

            if (j1 == j2)
            {
                l = v[i][j1] + ans(v, i + 1, j1 + dj1, j2 + dj2, dp);
            }
            else
            {
                l = v[i][j1] + v[i][j2] + ans(v, i + 1, j1 + dj1, j2 + dj2, dp);
            }

            maxi = max(maxi, l);
        }
    }

    return dp[i][j1][j2] = maxi;
}

// tabulation
int ans2(vector<vector<int>> v)
{

    int n = v.size();
    int m = v[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = v[n - 1][j1];
            else
            {
                dp[n - 1][j1][j2] = v[n - 1][j1] + v[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {

                int maxi = INT_MIN;

                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {

                        if (j1 + dj1 < 0 || j2 + dj2 < 0 || j1 + dj1 >= m || j2 + dj2 >= m)
                            continue;

                        int l = INT_MIN;

                        if (j1 == j2)
                        {
                            l = v[i][j1] + dp[i + 1][j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            l = v[i][j1] + v[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2];
                        }

                        maxi = max(l, maxi);
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m - 1];
}
int solve(int n, int m, vector<vector<int>> &v)
{

    return ans2(v);
}