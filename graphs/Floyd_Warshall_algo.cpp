#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> floyd_warshall(vector<pair<long long, pair<long long, long long>>> adj, long long n)
{

    vector<vector<long long>> ans(n + 1, vector<long long>(n + 1, INT_MAX));
    for (long long i = 1; i <= n; i++)
        ans[i][i] = 0;

    for (long long i = 0; i < adj.size(); i++)
    {
        ans[adj[i].first][adj[i].second.first] = adj[i].second.second;
        ans[adj[i].second.first][adj[i].first] = adj[i].second.second;
    }

    for (long long k = 1; k <= n; k++)
    {

        for (long long i = 1; i <= n; i++)
        {

            for (long long j = 1; j <= n; j++)
            {
                if (i == j || j == k || k == i)
                    continue;

                if (ans[i][k] == INT_MAX || ans[k][j] == INT_MAX)

                    continue;
                ans[i][j] = min(ans[i][k] + ans[k][j], ans[i][j]);
            }
        }
    }

    return ans;
}

int main()
{
    long long n, m, q;
    cin >> n >> m >> q;
    vector<pair<long long, pair<long long, long long>>> adj;
    while (m--)
    {
        long long n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        adj.push_back({n1, {n2, weight}});
    }

    vector<vector<long long>> ans = floyd_warshall(adj, n);

    while (q--)
    {
        long long u, v;
        cin >> u >> v;
        cout << ans[v][u] << "\n";
    }
}