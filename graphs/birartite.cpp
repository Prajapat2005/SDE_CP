#include <bits/stdc++.h>
using namespace std;

// use bfs
bool detect_cycle(vector<int> adj[], int z, vector<char> &visited)
{

    queue<pair<int, char>> q; // secont part is color of that node
    q.push({z, 'W'});
    char ch = 'B'; // ch has to paint nodes at the distanse of 1 from z
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int k = q.front().first;
            char l = q.front().second;
            visited[k] = l;
            q.pop();
            for (int j = 0; j < adj[k].size(); j++)
            {

                if (visited[adj[k][j]] == 'W')
                { // if node is visited with different colour from current paint(jo usko abhi paint hone wala tha us se alag)
                    if (ch != 'W')
                        return false;
                }
                if (visited[adj[k][j]] == 'B')
                {
                    if (ch != 'B')
                        return false;
                }

                if (visited[adj[k][j]] == 'n')
                    q.push({adj[k][j], ch}); // if not visited then paint with curr colour
            }
        }
        if (ch == 'W')
            ch = 'B';
        else
            ch = 'W';
    }

    return true;
}

bool detect(vector<int> adj[], int n)
{

    vector<char> visited(n + 1, 'n');

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 'n')
        {
            if (detect_cycle(adj, i, visited) == false)
                return false;
        }
    }
    return true;
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

    cout << detect(adj, n) << "\n";
}