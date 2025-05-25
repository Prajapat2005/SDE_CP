#include <bits/stdc++.h>
using namespace std;

bool detect_cycle(vector<int> adj[], int z, vector<int> &visited, vector<int> &visited_path)
{

    visited[z] = 1;
    visited_path[z] = 1;

    for (int i = 0; i < adj[z].size(); i++)
    {

        if (visited[adj[z][i]] == 0)
        {
            if (detect_cycle(adj, adj[z][i], visited, visited_path) == true)
                return true;
        }
        else if (visited_path[adj[z][i]] == 1)
        {
            return true;
        }
    }

    visited_path[z] = 0;
    return false;
}

bool detect(vector<int> adj[], int n)
{

    vector<int> visited(n + 1, 0);
    vector<int> visited_path(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (detect_cycle(adj, i, visited, visited_path) == true)
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
    }

    cout << detect(adj, n);
}