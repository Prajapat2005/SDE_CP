/* https://cses.fi/problemset/task/1668/ */

#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<int> adj[], vector<int> &vis, int z)
{

    queue<pair<int, int>> q;
    q.push({z, 2});
    vis[z] = 1;

    while (!q.empty())
    {
        int size;
        size = q.size();
        while (size--)
        {
            int ele = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (int i = 0; i < adj[ele].size(); i++)
            {
                if (vis[adj[ele][i]] == 3)
                {
                    vis[adj[ele][i]] = parent;
                    if (parent == 1)
                    {
                        q.push({adj[ele][i], 2});
                    }
                    else
                    {
                        q.push({adj[ele][i], 1});
                    }
                }
                else if (vis[adj[ele][i]] == 2)
                {
                    if (parent == 1)
                    {
                        return false;
                    }
                }
                else
                {
                    if (parent == 2)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n + 1, 3);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 3)
        {
            if (bfs(adj, ans, i) == false)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}