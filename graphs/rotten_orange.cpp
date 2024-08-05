#include <bits/stdc++.h>
using namespace std;

int time_required(vector<vector<int>> v, int n, int m)
{
    int count = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 2)
            {
                q.push({i, j});
                visited[i][j] = 2;
            }
        }
    }

    while (!q.empty())
    {
        int n2 = q.size();
        for (int i = 0; i < n2; i++)
        {
            int k = q.front().first;
            int l = q.front().second;
            q.pop();
            if (k + 1 < n && v[k + 1][l] == 1 && visited[k + 1][l] == 0)
            {
                q.push({k + 1, l});
                visited[k + 1][l] = 2;
            }
            if (k - 1 >= 0 && v[k - 1][l] == 1 && visited[k - 1][l] == 0)
            {
                q.push({k - 1, l});
                visited[k - 1][l] = 2;
            }
            if (l + 1 < m && v[k][l + 1] == 1 && visited[k][l + 1] == 0)
            {
                q.push({k, l + 1});
                visited[k][l + 1] = 2;
            }
            if (l - 1 >= 0 && v[k][l - 1] == 1 && visited[k][l - 1] == 0)
            {
                q.push({k, l - 1});
                visited[k][l - 1] = 2;
            }
        }

        count++;
    }
    return count - 1;
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
    cout << time_required(v, n, m);

    return 0;
}

// leetcode ans

bool check(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == 1)
                return false;
        }
    }
    return true;
}
int bfs(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int k = q.size();
        for (int i = 0; i < k; i++)
        {
            int k = q.front().first;
            int l = q.front().second;
            visited[k][l] = 1;
            q.pop();

            if (k - 1 >= 0 && visited[k - 1][l] == 0 && v[k - 1][l] == 1)
            {
                q.push({k - 1, l});
                v[k - 1][l] = 2;
            }
            if (l - 1 >= 0 && visited[k][l - 1] == 0 && v[k][l - 1] == 1)
            {
                q.push({k, l - 1});
                v[k][l - 1] = 2;
            }
            if (k + 1 < n && visited[k + 1][l] == 0 && v[k + 1][l] == 1)
            {
                q.push({k + 1, l});
                v[k + 1][l] = 2;
            }
            if (l + 1 < m && visited[k][l + 1] == 0 && v[k][l + 1] == 1)
            {
                q.push({k, l + 1});
                v[k][l + 1] = 2;
            }
        }

        count++;
    }
    if (check(v))
    {
        if (count == 0)
            return 0;
        else
            return count - 1;
    }

    return -1;
}

int orangesRotting(vector<vector<int>> &grid)
{
    return bfs(grid);
}