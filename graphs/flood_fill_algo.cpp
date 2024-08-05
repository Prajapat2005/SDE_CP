#include <bits/stdc++.h>
using namespace std;

void flood_fill_algo(vector<vector<int>> &v, int n, int m, int i, int j, int new_colour)
{

    int initian_index = v[i][j];
    vector<vector<int>> visited(n, vector<int>(m, 0));
    visited[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty())
    {

        int k = q.front().first;
        int l = q.front().second;
        q.pop();
        v[k][l] = new_colour;
        if (k + 1 < n && v[k + 1][l] == initian_index && visited[k + 1][l] == 0)
        {
            q.push({k + 1, l});
            visited[k + 1][l] = 1;
        }
        if (k - 1 >= 0 && v[k - 1][l] == initian_index && visited[k - 1][l] == 0)
        {
            q.push({k - 1, l});
            visited[k - 1][l] = 1;
        }
        if (k - 1 >= 0 && v[k][l + 1] == initian_index && visited[k][l + 1] == 0 && l + 1 < m)
        {
            q.push({k, l + 1});
            visited[k][l + 1] = 1;
        }
        if (k - 1 >= 0 && v[k][l - 1] == initian_index && visited[k][l - 1] == 0 && l - 1 >= 0)
        {
            q.push({k, l - 1});
            visited[k][l - 1] = 1;
        }
    }
}

int main()
{

    int n, m, i, j, new_colour;
    cin >> n >> m >> i >> j >> new_colour;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int l;
            cin >> l;
            v[i][j] = l;
        }
    }
    flood_fill_algo(v, n, m, i, j, new_colour);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// leetcode
void bfs(vector<vector<int>> &img, int sr, int sc, int color)
{

    queue<pair<int, int>> q;
    q.push({sr, sc});
    int i_color = img[sr][sc];
    img[sr][sc] = color;

    if (i_color == color)
        return;

    while (!q.empty())
    {
        int n = q.size();

        for (int k = 0; k < n; k++)
        {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            if (i - 1 >= 0 && img[i - 1][j] == i_color)
            {
                q.push({i - 1, j});
                img[i - 1][j] = color;
            }
            if (j - 1 >= 0 && img[i][j - 1] == i_color)
            {
                q.push({i, j - 1});
                img[i][j - 1] = color;
            }
            if (i + 1 < img.size() && img[i + 1][j] == i_color)
            {
                q.push({i + 1, j});
                img[i + 1][j] = color;
            }
            if (j + 1 < img[0].size() & img[i][j + 1] == i_color)
            {
                q.push({i, j + 1});
                img[i][j + 1] = color;
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{

    bfs(image, sr, sc, color);

    return image;
}