#include <bits/stdc++.h>
using namespace std;

int cheapest_flight(vector<pair<int, int>> adj[], int n, int dest, int step)
{

    vector<int> ans(n + 1, INT_MAX);
    ans[0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    q.push({0, {0, 0}}); // {step,{node,dist}}
    while (!q.empty())
    {

        int k = q.top().first;
        int node = q.top().second.first;
        int dist = q.top().second.second;
        q.pop();

        if (node != dest && k <= step)
        {
            for (int i = 0; i < adj[node].size(); i++)
            {

                int cost = adj[node][i].second + dist;
                if (cost < ans[adj[node][i].first])
                {
                    ans[adj[node][i].first] = cost;
                    q.push({k + 1, {adj[node][i].first, cost}});
                }
            }
        }
    }
    return ans[dest];
}

int main()
{

    int n, m, dest, step;
    cin >> n >> m >> dest >> step;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        adj[n1].push_back({n2, weight});
    }

    cout << cheapest_flight(adj, n, dest, step);
}