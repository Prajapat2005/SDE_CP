#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair
int mod = 1e9 + 7;

ii dfs(int node, vector<int> adj[], vector<ii> &dp, int n)
{

    if (node == n)
    {
        return mp(1, 1);
    }

    if (dp[node].f != -1 || dp[node].s != -1)
    {
        return dp[node];
    }

    int f = 0;
    int count = 0;
    for (auto it : adj[node])
    {

        ii x = dfs(it, adj, dp, n);
        if (x.s == 1)
        {
            f = 1;
            (count += x.f) %= mod;
        }
    }

    return dp[node] = mp(count, f);
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
    }

    vector<ii> dp(n + 1, mp(-1, -1));
    ii x = dfs(1, adj, dp, n);

    if (dp[1].s == 1)
    {
        cout << dp[1].f;
    }
    else
    {
        cout << 0;
    }
}