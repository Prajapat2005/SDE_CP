#include <bits/stdc++.h>
using namespace std;

int findMinDistance(vector<pair<int, int>> adj[], int N, int K, int source, int des)
{

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {source, 0}});

    int dist[N][K + 1];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            if (i == 0)
                dist[i][j] = 0;
            else
                dist[i][j] = INT_MAX;
        }
    }

    while (!pq.empty())
    {
        // it -> {dist, {node, leftout}}
        auto it = pq.top();
        pq.pop();

        int node = it.second.first;
        int x = it.second.second;
        int dis = dist[node][x]; // it.first

        for (auto iter : adj[node])
        {
            int y = iter.first;
            int d = iter.second;

            // at first lets do without leaving out any edges
            if (dis + d < dist[y][x])
            {
                dist[y][x] = dis + d;
                pq.push({-1 * (dis + d), {y, x}});
            }
            if (x == K)
                continue;

            if (dis < dist[y][x + 1])
            {
                dist[y][x + 1] = dis;
                pq.push({-1 * (dis), {y, x + 1}});
            }
        }
    }
    int mini = INT_MAX;

    for (int i = 0; i <= K; i++)
        mini = min(mini, dist[des][i]);
    return mini;
}

int main()
{
    int n, source, des, k;
    cin >> n >> source >> des >> k;

    int m, x;
    cin >> m >> x;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wr;
        cin >> u >> v >> wr;
        adj[u].push_back({v, wr});
        adj[v].push_back({u, wr});
    }

    cout << findMinDistance(adj, n, k, source, des);
}