#include <bits/stdc++.h>
using namespace std;

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

vector<int> dijkstra_algo_set(vector<pair<int, int>> adj[], int n, int z)
{

    vector<int> ans(n + 1, INT_MAX);
    ans[z] = 0;

    set<pair<int, int>> s;

    s.insert({0, z});
    while (!s.empty())
    {
        auto it = *(s.begin());
        int l = it.first;
        int k = it.second;
        s.erase(it);

        for (int i = 0; i < adj[k].size(); i++)
        {

            int count = adj[k][i].second + l;
            if (ans[adj[k][i].first] > count)
            {
                if (ans[adj[k][i].first] != INT_MAX)
                {
                    s.erase({ans[adj[k][i].first], adj[k][i].first});
                }
                ans[adj[k][i].first] = count;
                s.insert({count, adj[k][i].first});
            }
        }
    }
    return ans;
}

int main()
{

    int n, m, source;
    cin >> n >> m >> source;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {

        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        adj[n1].push_back({n2, weight});
        adj[n2].push_back({n1, weight});
    }
    vector<int> ans = dijkstra_algo_set(adj, n, source);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}