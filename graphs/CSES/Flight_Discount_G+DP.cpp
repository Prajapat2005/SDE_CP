#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

// graph + dp

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<ii> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        adj[u].push_back(mp(v, wt));
    }

    vector<vector<int>> dis(n, vector<int>(2, LLONG_MAX));

    dis[0][0] = 0;
    dis[0][1] = 0;

    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> q;
    q.push(mp(0, mp(0, 0)));

    while (!q.empty())
    {

        int d = q.top().f;
        int node = q.top().s.f;
        int k = q.top().s.s;

        q.pop();

        if (d != dis[node][k])
            continue;

        for (int i = 0; i < adj[node].size(); i++)
        {
            int count = dis[node][k] + adj[node][i].s;

            if (count < dis[adj[node][i].f][k])
            {

                dis[adj[node][i].f][k] = count;
                q.push(mp(count, mp(adj[node][i].f, k)));
            }

            if (k == 0)
            {
                if (dis[node][k] + (adj[node][i].s / 2) < dis[adj[node][i].f][1])
                {
                    dis[adj[node][i].f][1] = dis[node][k] + (adj[node][i].s / 2);

                    q.push(mp(dis[adj[node][i].f][1], mp(adj[node][i].f, 1)));
                }
            }
        }
    }

    cout << dis[n - 1][1];
}
