#include <bits/stdc++.h>
using namespace std;

int no_of_min_path(vector<pair<int, int>> adj[], int n)
{

    vector<int> dis(n + 1, INT_MAX);
    vector<int> ways(n + 1, 0);
    ways[0] = 1;
    dis[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0}); // wt,node
    while (!q.empty())
    {

        int node = q.top().second;
        int distance = q.top().first;
        q.pop();

        for (int i = 0; i < adj[node].size(); i++)
        {

            int count = adj[node][i].second + distance;

            if (count < dis[adj[node][i].first])
            {
                dis[adj[node][i].first] = count;
                ways[adj[node][i].first] = ways[node];
                q.push({count, adj[node][i].first});
            }
            else if (count == dis[adj[node][i].first])
            {
                ways[adj[node][i].first] = ways[node] + ways[adj[node][i].first];
            }
        }
    }

    return ways[n];
}

// 0---->n

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        adj[n1].push_back({n2, weight});
        adj[n2].push_back({n1, weight});
    }

    cout << no_of_min_path(adj, n);
}