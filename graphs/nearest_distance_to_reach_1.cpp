#include <bits/stdc++.h>
using namespace std;

void nearest_1(vector<vector<int>> &v, int n, int m)
{
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    int dis = 0;

    while (!q.empty())
    {

        int n2 = q.size();

        for (int i = 0; i < n2; i++)
        {
            int k = q.front().first;
            int l = q.front().second;
            v[k][l] = dis;
            q.pop();
            if (k + 1 < n && v[k + 1][l] == 0 && visited[k + 1][l] == 0)
            {
                q.push({k + 1, l});
                visited[k + 1][l] = 1;
            }
            if (k - 1 >= 0 && v[k - 1][l] == 0 && visited[k - 1][l] == 0)
            {
                q.push({k - 1, l});
                visited[k - 1][l] = 1;
            }
            if (l + 1 < m && v[k][l + 1] == 0 && visited[k][l + 1] == 0)
            {
                q.push({k, l + 1});
                visited[k][l + 1] = 1;
            }
            if (l - 1 >= 0 && v[k][l - 1] == 0 && visited[k][l - 1] == 0)
            {
                q.push({k, l - 1});
                visited[k][l - 1] = 1;
            }
        }
        dis++;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    nearest_1(v, n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}