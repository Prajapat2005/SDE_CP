// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dijkstra_algo(vector<pair<int, int>> adj[], int n, int z)
{

    vector<int> ans(n + 1, LLONG_MAX);
    ans[z] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, z});
    while (!q.empty())
    {

        int l = q.top().first;
        int k = q.top().second;
        q.pop();

        if (l != ans[k])
            continue;

        for (int i = 0; i < adj[k].size(); i++)
        {
            int count = adj[k][i].second + l;
            if (ans[adj[k][i].first] > count)
            {
                ans[adj[k][i].first] = count;
                q.push({count, adj[k][i].first});
            }
        }
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];

    while (m--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    vector<int> dis = dijkstra_algo(adj, n, 1);

    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}
