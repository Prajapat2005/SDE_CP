#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int MOD = 1000000007;

ll dp[1 << 21][22];
vector<int> adj[22];
int n;

ll dfs(int mask, int node)
{
    mask = mask ^ (1 << (node));
    if ((mask == 0) && (node == (n - 1)))
    {
        return 1;
    }
    if (node == (n - 1))
    {
        return 0;
    }
    if (dp[mask][node] != -1)
    {
        return dp[mask][node];
    }

    ll res = 0;
    for (auto &i : adj[node])
    {
        if ((1ll << (i)) & mask)
        {
            res += dfs(mask, i);
            res %= MOD;
        }
    }
    return (dp[mask][node] = res);
}
int main()
{
    fastio;
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs((1 << n) - 1, 0);
}