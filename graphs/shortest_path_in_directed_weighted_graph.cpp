#include <bits/stdc++.h>
using namespace std;

void topological(vector<pair<long long, long long>> adj[], long long z, vector<long long> &visited, stack<long long> &s)
{

    visited[z] = 1;
    for (long long i = 0; i < adj[z].size(); i++)
    {

        if (visited[adj[z][i].first] == 0)
            topological(adj, adj[z][i].first, visited, s);
    }

    s.push(z);
}

stack<long long> topological_sorting(vector<pair<long long, long long>> adj[], long long n)
{

    vector<long long> visited(n + 1, 0);
    stack<long long> s;
    for (long long i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            topological(adj, i, visited, s);
    }

    return s;
}

vector<long long> shortest_path(vector<pair<long long, long long>> adj[], stack<long long> s, long long n, long long z)
{

    vector<long long> ans(n + 1, 1e15);
    ans[z] = 0;
    while (!s.empty())
    {
        long long k = s.top();
        s.pop();

        for (long long i = 0; i < adj[k].size(); i++)
        {
            long long weight = adj[k][i].second;
            weight = weight + ans[k];
            ans[adj[k][i].first] = min(ans[adj[k][i].first], weight);
        }
    }

    return ans;
}

int main()
{

    long long n, m, source;
    cin >> n >> m >> source;
    vector<pair<long long, long long>> adj[n + 1];
    for (long long i = 0; i < m; i++)
    {
        long long n1, n2, w;
        cin >> n1 >> n2 >> w;
        adj[n1].push_back({n2, w});
    }

    stack<long long> s = topological_sorting(adj, n);
    vector<long long> ans = shortest_path(adj, s, n, source);

    for (long long i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}