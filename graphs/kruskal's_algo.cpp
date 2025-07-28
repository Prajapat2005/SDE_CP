#include <bits/stdc++.h>
using namespace std;

int kruskal_algo(vector<pair<int, pair<int, int>>> adj, int n)
{

    sort(adj.begin(), adj.end());
    vector<pair<int, int>> tree;
    int wt = 0;
    vector<int> visited(n + 1, 0);
    for (int i = 0; i < adj.size(); i++)
    {

        int u = adj[i].second.first; // u-->v
        int v = adj[i].second.second;
        int cost = adj[i].first;

        if (visited[v] == 0 || visited[u] == 0)
        {
            wt = wt + cost;
            visited[v] = 1;
            visited[u] = 1;
            tree.push_back({u, v});
        }
    }

    return wt;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        adj.push_back({weight, {n1, n2}});
    }

    cout << kruskal_algo(adj, n);
}