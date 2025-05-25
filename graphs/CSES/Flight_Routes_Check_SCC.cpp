#include <bits/stdc++.h>
using namespace std;

void topo_sort(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{

    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            topo_sort(it, adj, vis, st);
        }
    }

    st.push(node);
}

void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> adj2[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }

    stack<int> st;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            topo_sort(i, adj, vis, st);
        }
    }

    fill(vis.begin(), vis.end(), 0);

    vector<int> ans;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            dfs(node, vis, adj2);
            ans.push_back(node);
            if (ans.size() == 2)
            {
                break;
            }
        }
    }

    if (ans.size() == 2)
    {
        cout << "NO" << "\n";
        cout << ans[1] << " " << ans[0];
    }
    else
    {
        cout << "YES";
    }
}