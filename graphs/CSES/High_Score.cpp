#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

void dfs(int node, vector<int> &vis, vector<int> adj[])
{

    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (vis[adj[node][i]] == 0)
        {
            dfs(adj[node][i], vis, adj);
        }
    }
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ii, int>> v(m);
    vector<int> adj1[n + 1];
    vector<int> adj2[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, vt, wt;
        cin >> u >> vt >> wt;
        v[i] = mp(mp(u, vt), -wt);
        adj1[u].push_back(vt);
        adj2[vt].push_back(u);
    }

    vector<int> vis1(n + 1, 0);
    vector<int> vis2(n + 1, 0);
    dfs(1, vis1, adj1);
    dfs(n, vis2, adj2);

    vector<int> dis(n + 1, LLONG_MAX);

    int k = n;
    dis[1] = 0;
    while (k--)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (dis[v[i].f.f] == LLONG_MAX)
                continue;

            if (dis[v[i].f.f] + v[i].s < dis[v[i].f.s])
            {
                dis[v[i].f.s] = dis[v[i].f.f] + v[i].s;

                if (k == 0 && vis1[v[i].f.s] && vis2[v[i].f.s])
                {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << -dis[n];
    return 0;
}