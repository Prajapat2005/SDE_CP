#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node, vector<int> &vis, vector<int> &ans)
{

    ans.push_back(node);
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (vis[adj[node][i]] != 1)
            dfs(adj, adj[node][i], vis, ans);
    }
}

void dfs_2(vector<int> adj[], int node, vector<int> &vis)
{

    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (vis[adj[node][i]] != 1)
            dfs_2(adj, adj[node][i], vis);
    }
}

// number of graph
int number_of_provinces(vector<int> &vis, vector<int> adj[], int n)
{
    int count = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (vis[i] != 1)
        {
            dfs_2(adj, i, vis);
            count++;
        }
    }
    return count;
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
    vector<int> vis(n + 1, 0);
    vis[1] = 1;
    vector<int> ans;
    //  dfs(adj,1,vis,ans);
    // for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout << number_of_provinces(vis, adj, n);
}

/*
8 8
1 2
1 6
2 3
2 4
6 7
6 8
4 5
7 5

1 2 3 4 5 7 6 8 */