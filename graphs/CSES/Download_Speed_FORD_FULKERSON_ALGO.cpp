#include <bits/stdc++.h>
using namespace std;
#define int long long

// max flow in graph

bool dfs(int node, int dest, vector<vector<int>> &adj, vector<int> &vis /* , int &threshold */, vector<int> &path)
{
    vis[node] = 1;

    if (node == dest)
    {
        path.push_back(node);
        return true;
    }

    for (int i = 1; i <= dest; i++)
    {
        if (adj[node][i] <= 0)
        {
            continue;
        }

        /* if (adj[node][i] == -1 || adj[node] < threshold)
        {
            continue;
        } */

        if (vis[i])
        {
            continue;
        }

        if (dfs(i, dest, adj, vis /* , threshold */, path))
        {
            path.push_back(node);
            return true;
        }
    }

    return false;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, -1));

    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (adj[u][v] == -1)
        {
            adj[u][v] = 0;
        }
        adj[u][v] += w;

        if (adj[v][u] == -1)
        {
            adj[v][u] = 0;
        }
        sum += w;
    }

    int ans = 0;

    while (/* sum > 0 */ true)
    {
        vector<int> vis(n + 1, 0);
        vector<int> path;
        bool f = dfs(1, n, adj, vis, /*  sum, */ path);

        if (f)
        {
            reverse(path.begin(), path.end());

            int mini = LLONG_MAX;
            for (int i = 0; i < path.size() - 1; i++)
            {
                mini = min(mini, adj[path[i]][path[i + 1]]);
            }

            ans += mini;

            for (int i = 0; i < path.size() - 1; i++)
            {
                adj[path[i]][path[i + 1]] -= mini;
                adj[path[i + 1]][path[i]] += mini;
            }
        }
        else
        {
            /* sum/=2; */
            break;
        }
    }

    cout << ans << "\n";
}