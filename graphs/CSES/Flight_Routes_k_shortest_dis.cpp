#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

// need to see video

int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ii> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(mp(v, wt));
    }

    priority_queue<ii, vector<ii>, greater<ii>> q;

    priority_queue<int> dis[n + 1];

    q.push(mp(0, 1));
    dis[1].push(0);

    while (!q.empty())
    {
        ii x = q.top();
        q.pop();

        if (x.f > dis[x.s].top())
        {
            continue;
        }

        for (int i = 0; i < adj[x.s].size(); i++)
        {
            int count = x.f + adj[x.s][i].s;

            if (dis[adj[x.s][i].f].size() < k)
            {
                dis[adj[x.s][i].f].push(count);
                q.push(mp(count, adj[x.s][i].f));
            }
            else if (count < dis[adj[x.s][i].f].top())
            {
                dis[adj[x.s][i].f].pop();
                dis[adj[x.s][i].f].push(count);
                q.push(mp(count, adj[x.s][i].f));
            }
        }
    }

    vector<int> ans;

    while (dis[n].size())
    {
        ans.push_back(dis[n].top());
        dis[n].pop();
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}