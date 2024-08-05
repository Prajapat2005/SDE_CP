#include <bits/stdc++.h>
using namespace std;

bool detect_safe_node(vector<int> adj[], int z, vector<int> &visited, vector<int> &visited_path, vector<int> &check)
{

    visited[z] = 1;
    visited_path[z] = 1;
    check[z] = 0;
    for (int i = 0; i < adj[z].size(); i++)
    {

        if (visited[adj[z][i]] == 0)
        {
            if (detect_safe_node(adj, adj[z][i], visited, visited_path, check) == true)
            {
                check[adj[z][i]] = 0; // cycle detected
                return true;
            }
        }
        else if (visited_path[adj[z][i]] == 1)
        {
            check[adj[z][i]] = 0; // part of cycle
            return true;
        }
    }

    check[z] = 1; // no cycle then it is safe node
    visited_path[z] = 0;
    return false;
}

vector<int> safe_node(vector<int> adj[], int n)
{

    vector<int> visited(n + 1, 0);
    vector<int> visited_path(n + 1, 0);
    vector<int> check(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            detect_safe_node(adj, i, visited, visited_path, check);
        }
    }
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        if (check[i] == 1)
            ans.push_back(i);
    }
    return ans;
}

// reverse direction of graph and apply topo sort
vector<int> topo(vector<int> adj[], int v)
{

    vector<int> incomming(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            incomming[adj[i][j]]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (incomming[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int x = q.front();
        ans.push_back(x);

        q.pop();

        for (int i = 0; i < adj[x].size(); i++)
        {
            incomming[adj[x][i]]--;

            if (incomming[adj[x][i]] == 0)
            {
                q.push(adj[x][i]);
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}
vector<int> eventualSafeNodes(vector<vector<int>> &v)
{

    vector<int> adj[v.size()];

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            adj[v[i][j]].push_back(i);
        }
    }

    return topo(adj, v.size());
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i <= m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
    }

    vector<int> ans = safe_node(adj, n);
}