/*https://cses.fi/problemset/task/1669*/
#include <bits/stdc++.h>
using namespace std;

bool cycle(vector<int> adj[], int z, int prev, int &start, int &end, vector<int> &vis, vector<int> &parent)
{

    vis[z] = 1;
    for (auto it : adj[z])
    {
        if (vis[it] == 0)
        {
            parent[it] = z;
            if (cycle(adj, it, z, start, end, vis, parent) == true)
            {
                return true;
            }
        }
        else if (it != prev)
        {
            start = z;
            end = it;
            return true;
        }
    }

    return false;
}

bool solve(vector<int> adj[], vector<int> &ans, int n)
{

    int start;
    int end;

    vector<int> vis(n + 1, 0);
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (cycle(adj, i, -1, start, end, vis, parent) == true)
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
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    if (solve(adj, ans, n) == true)
    {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}