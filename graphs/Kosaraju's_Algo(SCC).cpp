#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &visited, vector<int> &ans, int n)
{

    if (visited[n] == 0)
        return;

    visited[n] = 0;
    ans.push_back(n);

    for (int i = 0; i < adj[n].size(); i++)
    {
        dfs(adj, visited, ans, adj[n][i]);
    }
}

vector<int> finishing(vector<int> adj[], int n)
{

    vector<int> ans;
    vector<int> visited(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
        if (visited[i] == 1)
        {
            dfs(adj, visited, ans, i);
        }
    }

    return ans;
}

vector<vector<int>> SCC(vector<int> adj[], int n)
{

    vector<int> finishing_time = finishing(adj, n);

    // reversing
    vector<int> rev_adj[n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {

            rev_adj[adj[i][j]].push_back(i);
        }
    }

    adj = rev_adj;

    vector<vector<int>> ans;
    vector<int> visited(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
        if (visited[finishing_time[i]] == 1)
        {

            vector<int> SCC_1;
            dfs(adj, visited, SCC_1, finishing_time[i]);
            ans.push_back(SCC_1);
        }
    }

    return ans;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
    }

    vector<vector<int>> ans = SCC(adj, n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}