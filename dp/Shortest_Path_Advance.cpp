// https://codeforces.com/contest/2049/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m)));

        vector<vector<int>> ans(n, vector<int>(m, LLONG_MAX));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int x = 0; x < m; x++)
                {
                    if (i == 0)
                    {
                        if (j == 0)
                        {
                            dp[i][j][x] = k * x + v[i][(j + x) % m];
                        }
                        else
                        {
                            dp[i][j][x] = dp[i][j - 1][x] + v[i][(j + x) % m];
                        }
                    }
                    else if (j == 0)
                    {
                        dp[i][j][x] = k * x + v[i][(j + x) % m] + ans[i - 1][j];
                    }
                    else
                    {
                        dp[i][j][x] = min(k * x + v[i][(j + x) % m] + ans[i - 1][j], dp[i][j - 1][x] + v[i][(j + x) % m]);
                    }
                    ans[i][j] = min(ans[i][j], dp[i][j][x]);
                }
            }
        }

        cout << ans[n - 1][m - 1] << "\n";
    }

    return 0;
}
