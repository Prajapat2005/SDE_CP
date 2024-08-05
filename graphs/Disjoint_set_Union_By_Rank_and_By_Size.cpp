#include <bits/stdc++.h>
using namespace std;

int find_ultimate_parent(vector<int> &parent, int u)
{

    if (u == parent[u])
        return u;

    return parent[u] = find_ultimate_parent(parent, parent[u]);
}

void Union_By_Rank(vector<pair<int, int>> adj, int n)
{

    vector<int> rank(n + 1, 0);
    vector<int> parent(n + 1, 0);
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < adj.size(); i++)
    {

        int u = adj[i].first;
        int v = adj[i].second;

        int pu = find_ultimate_parent(parent, u);
        int pv = find_ultimate_parent(parent, v);

        if (pu == pv)
            continue;

        if (rank[pu] == rank[pv])
        {
            parent[pv] = pu;
            rank[pu]++;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
        }
    }

    for (int i = 0; i < parent.size(); i++)
        cout << parent[i] << " ";
    cout << "\n";
    for (int i = 0; i < rank.size(); i++)
        cout << rank[i] << " ";
}

void Union_By_Size(vector<pair<int, int>> adj, int n)
{

    vector<int> size(n + 1, 1);
    vector<int> parent(n + 1, 0);
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < adj.size(); i++)
    {

        int u = adj[i].first;
        int v = adj[i].second;

        int pu = parent[find_ultimate_parent(parent, u)];
        int pv = parent[find_ultimate_parent(parent, v)];

        if (size[pu] == size[pv])
        {
            parent[pv] = pu;
            size[pu] = size[pu] + size[pv];
        }
        else if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] = size[pu] + size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] = size[pu] + size[pv];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int x = find_ultimate_parent(parent, i);
    }

    for (int i = 0; i < parent.size(); i++)
        cout << parent[i] << " ";
    cout << "\n";
    for (int i = 0; i < size.size(); i++)
        cout << size[i] << " ";
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj;
    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj.push_back({n1, n2});
    }

    Union_By_Rank(adj, n);
    cout << "\n";
    Union_By_Size(adj, n);
}