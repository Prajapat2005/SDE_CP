#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define int long long
int mod = 998244353;

// https://atcoder.jp/contests/abc362/tasks/abc362_e

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }

    /*
    N^4
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));

    for (int i = 0; i < n; i++)
    {
        dp[i][i][1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            dp[i][j][2] = 1;
        }
    }

    for (int i = n - 3; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 3; k <= n; k++)
            {
                for (int l = j + 1; l < n; l++)
                {
                    if (v[j] - v[i] == v[l] - v[j])
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[j][l][k - 1]) % mod;
                    }
                }
            }
        }
    } */

    vector<vector<map<int, int>>> dp(n, vector<map<int, int>>(n + 1));
    // N^3*log(N)
    for (int i = n - 1; i >= 0; i--)
    {
        for (int k = 2; k <= n; k++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = v[j] - v[i];
                if (k == 2)
                {
                    dp[i][k][diff]++;
                }
                else
                {
                    dp[i][k][diff] = (dp[i][k][diff] + dp[j][k - 1][diff]) % mod;
                }
            }
        }
    }

    vector<int> arr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int k = 2; k <= n; k++)
        {
            for (auto it : dp[i][k])
            {
                arr[k] = (arr[k] + it.second) % mod;
            }
        }
    }

    arr[1] = n;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}