#include <bits/stdc++.h>
using namespace std;

// use bfs
bool detect_cycle(vector<int> adj[], int z, vector<int> &visited)
{

    queue<pair<int, int>> q;
    q.push({z, -1});
    visited[z] = 1;

    while (!q.empty())
    {

        int k = q.front().first;
        int l = q.front().second;

        for (int i = 0; i < adj[k].size(); i++)
        {

            if (adj[k][i] == l)
                continue;

            if (visited[i] == 1)
                return true;

            if (adj[k][i] != l)
            {
                q.push({i, k});
                visited[i] = 1;
            }
        }
    }
    return false;
}

bool detect(vector<int> adj[], int n)
{

    vector<int> visited(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (detect_cycle(adj, i, visited) == true)
                return true;
        }
    }
    return false;
}

// use dfs
bool detect_cycle_2(vector<int> adj[], int k, int prev, vector<int> &visited)
{
    visited[k] = 1;
    for (int i = 0; i < adj[k].size(); i++)
    {
        if (adj[k][i] == prev)
            continue;

        if (visited[adj[k][i]] == 1)
            return true;

        if (adj[k][i] != prev)
        {
            if (detect_cycle_2(adj, adj[k][i], k, visited) == true)
                return true;
        }
    }

    return false;
}

bool detect_2(vector<int> adj[], int n)
{

    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            if (detect_cycle_2(adj, i, -1, visited) == true)
                return true;
        }
    }
    return false;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
}