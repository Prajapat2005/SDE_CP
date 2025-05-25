#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_distance(vector<int> adj[], int n, int z)
{
    queue<pair<int, int>> q;
    q.push({z, 0});
    vector<int> ans(n + 1, INT_MAX);
    ans[z] = 0;
    while (!q.empty())
    {

        int k = q.front().first;
        int dis = q.front().second;
        q.pop();
        for (int i = 0; i < adj[k].size(); i++)
        {

            int count = 1 + dis;

            if (count < ans[adj[k][i]])
            {
                ans[adj[k][i]] = count;
                q.push({adj[k][i], count});
            }
        }
    }

    return ans;
}

int main()
{

    int n, m, source;
    cin >> n >> m >> source;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<int> ans = shortest_distance(adj, n, source);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}