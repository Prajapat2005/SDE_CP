#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floyd_warshall(vector<pair<int, pair<int, int>>> adj, int n)
{

    vector<vector<int>> ans(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 0; i <= n; i++)
        ans[i][i] = 0;

    for (int i = 0; i < adj.size(); i++)
    {
        ans[adj[i].first][adj[i].second.first] = adj[i].second.second;
    }

    for (int k = 0; k <= n; k++)
    {

        for (int i = 0; i <= n; i++)
        {

            for (int j = 0; j <= n; j++)
            {

                if (i != k && j != k && i != j)
                {

                    if (adj[i][k] == -1 || adj[k][j] == -1)
                        continue;
                    else
                    {
                        adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (ans[i][j] == 1e9)
                ans[i][j] = -1;
        }
    }

    return ans;
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
        adj.push_back({n1, {n2, weight}});
    }

    vector<vector<int>> ans = floyd_warshall(adj, n);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}