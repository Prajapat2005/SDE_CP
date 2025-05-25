#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/graph/2SAT.html

int neg(int n, int m)
{
    return 2 * m - n + 1;
}

void dfs1(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{

    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs1(it, st, vis, adj);
        }
    }

    st.push(node);
}

void dfs2(int node, vector<int> adj[], vector<int> &comp, int &k)
{

    comp[node] = k;

    for (auto &it : adj[node])
    {
        if (!comp[it])
        {
            dfs2(it, adj, comp, k);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj1[m * 2 + 1];
    vector<int> adj2[m * 2 + 1];

    for (int i = 0; i < n; i++)
    {

        int a, b;
        char ca, cb;

        cin >> ca >> a >> cb >> b;

        if (ca == '-')
        {
            a = neg(a, m);
        }
        if (cb == '-')
        {
            b = neg(b, m);
        }

        adj1[neg(a, m)].push_back(b);
        adj1[neg(b, m)].push_back(a);
        adj2[a].push_back(neg(b, m));
        adj2[b].push_back(neg(a, m));
    }

    stack<int> st;
    vector<int> vis(2 * m + 1);

    for (int i = 1; i <= 2 * m; i++)
    {
        if (!vis[i])
        {
            dfs1(i, st, vis, adj1);
        }
    }

    vector<int> comp(2 * m + 1);
    int k = 1;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (comp[node])
            continue;

        dfs2(node, adj2, comp, k);
        k++;
    }

    vector<int> ans(m + 1);

    for (int i = 1; i <= m; i++)
    {
        if (comp[i] == comp[neg(i, m)])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }

        ans[i] = (comp[i] > comp[neg(i, m)]);
    }

    for (int i = 1; i <= m; i++)
    {
        cout << ((ans[i]) ? ('+') : ('-')) << " ";
    }
}