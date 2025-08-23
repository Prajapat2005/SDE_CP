// https://leetcode.com/problems/minimum-cost-path-with-teleportations/

class Solution
{
public:
    int minCost(vector<vector<int>> &grid, int k)
    {

        int n = grid.size();
        int m = grid[0].size();
        int maxi = 10000;
        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MAX)));
        vector<int> prev_suf(maxi + 1, INT_MAX);

        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0][0] = 0;

        vector<vector<bool>> inq(n, vector<bool>(m, false));
        inq[0][0] = true;

        while (!q.empty())
        {

            auto [i, j] = q.front();
            q.pop();
            inq[i][j] = false;

            if (i + 1 < n)
            {
                if (dist[i + 1][j][0] > grid[i + 1][j] + dist[i][j][0])
                {
                    dist[i + 1][j][0] = grid[i + 1][j] + dist[i][j][0];
                    if (!inq[i + 1][j])
                    {
                        inq[i + 1][j] = true;
                        q.push({i + 1, j});
                    }
                }
            }

            if (j + 1 < m)
            {
                if (dist[i][j + 1][0] > grid[i][j + 1] + dist[i][j][0])
                {
                    dist[i][j + 1][0] = grid[i][j + 1] + dist[i][j][0];
                    if (!inq[i][j + 1])
                    {
                        inq[i][j + 1] = true;
                        q.push({i, j + 1});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prev_suf[grid[i][j]] = min(prev_suf[grid[i][j]], dist[i][j][0]);
            }
        }

        for (int i = maxi - 1; i >= 0; i--)
        {
            prev_suf[i] = min(prev_suf[i], prev_suf[i + 1]);
        }

        for (int tele = 1; tele <= k; tele++)
        {

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dist[i][j][tele] = prev_suf[grid[i][j]];
                }
            }

            vector<int> curr_suf(maxi + 1, INT_MAX);

            // inq -> false
            // q -> empty

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (dist[i][j][tele] < INT_MAX)
                    {
                        q.push({i, j});
                        inq[i][j] = true;
                    }
                }
            }

            while (!q.empty())
            {
                auto [i, j] = q.front();
                q.pop();
                inq[i][j] = false;

                if (i + 1 < n)
                {
                    if (dist[i + 1][j][tele] >
                        grid[i + 1][j] + dist[i][j][tele])
                    {
                        dist[i + 1][j][tele] =
                            grid[i + 1][j] + dist[i][j][tele];
                        if (!inq[i + 1][j])
                        {
                            inq[i + 1][j] = true;
                            q.push({i + 1, j});
                        }
                    }
                }

                if (j + 1 < m)
                {
                    if (dist[i][j + 1][tele] >
                        grid[i][j + 1] + dist[i][j][tele])
                    {
                        dist[i][j + 1][tele] =
                            grid[i][j + 1] + dist[i][j][tele];
                        if (!inq[i][j + 1])
                        {
                            inq[i][j + 1] = true;
                            q.push({i, j + 1});
                        }
                    }
                }
            }

            if (tele == k)
            {
                break;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    curr_suf[grid[i][j]] =
                        min(curr_suf[grid[i][j]], dist[i][j][tele]);
                }
            }

            for (int i = maxi - 1; i >= 0; i--)
            {
                curr_suf[i] = min(curr_suf[i], curr_suf[i + 1]);
            }

            prev_suf = curr_suf;
        }

        return dist[n - 1][m - 1][k];
    }
};