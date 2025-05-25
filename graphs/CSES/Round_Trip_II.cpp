#include <bits/stdc++.h>
using namespace std;
#define int long long

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &p_vis, vector<int> &parent, int &start, int &end)
{

    vis[node] = 1;
    p_vis[node] = 1;

    for (auto &it : adj[node])
    {

        if (vis[it] == 0)
        {
            parent[it] = node;
            if (dfs(it, adj, vis, p_vis, parent, start, end) == true)
            {
                return true;
            }
        }
        else if (p_vis[it])
        {

            end = it;
            start = node;

            return true;
        }
    }

    p_vis[node] = 0;
    return false;
}

bool solve(vector<int> adj[], vector<int> &ans, int n)
{

    int start, end;

    vector<int> vis(n + 1, 0);
    vector<int> p_vis(n + 1, 0);
    vector<int> parent(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, p_vis, parent, start, end))
            {
                ans.push_back(end);
                while (start != end)
                {
                    ans.push_back(start);
                    start = parent[start];
                }
                ans.push_back(end);
                return true;
            }
        }
    }

    return false;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> parent;

    if (solve(adj, parent, n))
    {
        cout << parent.size() << "\n";
        for (int i = parent.size() - 1; i >= 0; i--)
        {
            cout << parent[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}