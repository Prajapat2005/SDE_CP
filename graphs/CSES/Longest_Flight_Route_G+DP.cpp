#include <bits/stdc++.h>
using namespace std;
#define int long long

// good question of graph + dp

vector<int> solve(int node, vector<int> adj[], vector<vector<int>> &dp, int &n)
{

    if (node == n)
    {
        return {1, -1, 1};
    }

    if (dp[node][0] != -1 || dp[node][1] != -1 || dp[node][2] != -1)
    {
        return dp[node];
    }

    int f = 0;
    int dis = 0;
    int next_city = -1;

    for (auto &it : adj[node])
    {
        vector<int> v = solve(it, adj, dp, n);

        if (v[2] == 1)
        {
            f = 1;
            if (dis < v[0])
            {
                dis = v[0];
                next_city = it;
            }
        }
    }

    return dp[node] = {dis + 1, next_city, f};
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }

    //{dis,nextcity,flag}

    vector<vector<int>> dp(n + 1, vector<int>(3, -1));

    vector<int> v = solve(1, adj, dp, n);

    if (dp[1][2] != 1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << dp[1][0] << "\n";
        int x = 1;
        while (dp[x][1] != -1)
        {
            cout << x << " ";
            x = dp[x][1];
        }
        cout << x << "\n";
    }
}