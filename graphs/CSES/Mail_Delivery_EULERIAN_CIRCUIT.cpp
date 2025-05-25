#include <bits/stdc++.h>
using namespace std;

// Eulerian path
// https://youtu.be/3BJTw_OWvTU?si=GOjyOljC7WadhyZs
// A Eulerian path is a path in a graph that passes through all of its edges exactly once. A Eulerian cycle is a Eulerian path that is a cycle.

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> adj[n];
    vector<int> deg(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        deg[u]++;
        deg[v]++;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (deg[i] & 1)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<int> ans;
    stack<int> st;
    st.push(0);

    while (!st.empty())
    {
        int node = st.top();

        if (adj[node].empty())
        {
            ans.push_back(node);
            st.pop();
        }
        else
        {
            int i = *(adj[node].begin());
            adj[i].erase(node);
            adj[node].erase(i);
            st.push(i);
        }
    }

    if (ans.size() != (m + 1))
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (auto &it : ans)
    {
        cout << it + 1 << " ";
    }
}

/*
void dfs(int node, set<int> adj[], vector<int> &vis)
{

    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    vector<int> adj2[n];
    vector<int> deg(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u][v]++;
        adj[v][u]++;
        deg[u]++;
        deg[v]++;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<int> vis(n, 0);
    dfs(0, adj2, vis);

    for (int i = 0; i < n; i++)
    {
        if (deg[i])
        {
            if (deg[i] & 1 || (vis[i] == 0))
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    vector<int> ans;
    stack<int> st;
    st.push(0);

    while (!st.empty())
    {
        int node = st.top();
        int i;
        for (i = 0; i < n; i++)
        {
            if (adj[node][i])
            {
                break;
            }
        }

        if (i == n)
        {
            ans.push_back(node);
            st.pop();
        }
        else
        {
            adj[i][node]--;
            adj[node][i]--;
            st.push(i);
        }
    }

    for (auto &it : ans)
    {
        cout << it + 1 << " ";
    }
} */