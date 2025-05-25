#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], stack<int> &st, vector<int> &vis)
{

    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, st, vis);
        }
    }

    st.push(node);
}

int dfs(int node, vector<int> adj[], vector<int> &dp, vector<int> &parent)
{

    if (dp[node])
    {
        return dp[node];
    }

    int ans = 0;

    for (auto it : adj[node])
    {
        int x = dfs(it, adj, dp, parent);

        if (ans < x)
        {
            parent[node] = it;
            ans = x;
        }
    }

    return dp[node] = 1 + ans;
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

    stack<int> st;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, st, vis);
        }
    }

    fill(vis.begin(), vis.end(), 0);
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int ans = 0;
    int x;

    while (!st.empty())
    {
        if (vis[st.top()] == 0)
        {
            int X = dfs(st.top(), adj, vis, parent);
            if (ans < X)
            {
                ans = X;
                x = st.top();
            }
        }
        st.pop();
    }

    vector<int> arr;
    arr.push_back(x);
    while (parent[x] != x)
    {
        x = parent[x];
        arr.push_back(x);
    }

    cout << arr.size() << "\n";
    for (auto &it : arr)
    {
        cout << it << " ";
    }
}