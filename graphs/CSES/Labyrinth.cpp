#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

// good question
// https://cses.fi/problemset/result/11591537/
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));

    ii start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                start = mp(i, j);
            }
            else if (v[i][j] == 'B')
            {
                end = mp(i, j);
            }
        }
    }

    vector<vector<int>> prev(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m, false));
    queue<ii> q;
    q.push(start);
    vis[start.f][start.s] = true;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    string stepDir = "URDL";

    while (!q.empty())
    {
        ii x = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int new_x = x.f + dx[i];
            int new_y = x.s + dy[i];

            if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
                continue;

            if (vis[new_x][new_y] || v[new_x][new_y] == '#')
                continue;

            vis[new_x][new_y] = true;
            prev[new_x][new_y] = i;
            q.push({new_x, new_y});
        }
    }

    if (vis[end.f][end.s])
    {
        vector<int> dir;
        while (end != start)
        {
            int p = prev[end.f][end.s];
            dir.push_back(p);
            end = mp(end.f - dx[p], end.s - dy[p]);
        }

        reverse(dir.begin(), dir.end());
        cout << "YES" << "\n";
        cout << dir.size() << "\n";
        for (int i = 0; i < dir.size(); i++)
        {
            cout << stepDir[dir[i]];
        }
    }
    else
    {
        cout << "NO" << "\n";
    }
    return 0;
}
