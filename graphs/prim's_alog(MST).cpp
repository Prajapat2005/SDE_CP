#include <bits/stdc++.h>
using namespace std;

int min_spanning_tree(vector<pair<int, int>> adj[], int n, vector<pair<int, int>> &MST)
{

    vector<int> vis(n + 1, 0);
    int sum = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {0, -1}}); //{wt,node,parent}

    while (!q.empty())
    {

        int wt = q.top().first;
        int node = q.top().second.first;
        int parent = q.top().second.second;
        q.pop();

        if (vis[node] == 0)
        {

            if (parent != -1)
                MST.push_back({parent, node});
            sum = sum + wt;
            vis[node] = 1;

            for (int i = 0; i < adj[node].size(); i++)
            {
                if (vis[adj[node][i].first] == 0)
                    q.push({adj[node][i].second, {adj[node][i].first, node}});
            }
        }
    }

    return sum;
}

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

    vector<pair<int, int>> MST;

    cout << min_spanning_tree(adj, n, MST);
    cout << "\n";
    for (int i = 0; i < MST.size(); i++)
    {
        cout << MST[i].first << " " << MST[i].second << "\n";
    }
}