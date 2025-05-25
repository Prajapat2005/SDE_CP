/* https://cses.fi/problemset/task/1667 */

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int &n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    queue<int> q;
    vector<int> parent(n + 1);
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();

        if (ele == n)
        {
            break;
        }

        for (int i = 0; i < adj[ele].size(); i++)
        {
            if (vis[adj[ele][i]] == 0)
            {
                parent[adj[ele][i]] = ele;
                vis[adj[ele][i]] = 1;
                q.push(adj[ele][i]);
            }
        }
    }

    return parent;
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

    vector<int> parent = bfs(n, adj);
    if (parent[n] == 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> ans;
        int i = n;
        while (i != 0)
        {
            ans.push_back(i);
            i = parent[i];
        }
        cout << ans.size() << "\n";

        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
    }
}