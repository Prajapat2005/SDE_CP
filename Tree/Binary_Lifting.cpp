#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths-ii/

class Solution
{
public:
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> up;
    vector<vector<int>> distup;
    int max_up = 18; // 100,000
    vector<int> depth;

    void dfs(int node, int p)
    {

        up[node][0] = p;

        for (auto &[child, wt] : adj[node])
        {

            if (child == p)
            {
                continue;
            }

            depth[child] = depth[node] + 1;
            distup[child][0] = wt;
            dfs(child, node);
        }
    }

    int distt(int u, int v)
    {

        int diff = depth[u] - depth[v];

        int res = 0;

        for (int i = max_up; i >= 0; i--)
        {

            if (diff & (1 << i))
            {
                res += distup[u][i];
                u = up[u][i];
            }
        }

        return res;
    }

    int lca(int u, int v)
    {

        if (depth[u] < depth[v])
        {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int i = max_up; i >= 0; i--)
        {
            if (diff & (1 << i))
            {
                u = up[u][i];
            }
        }

        if (u == v)
        {
            return u;
        }

        for (int i = max_up; i >= 0; i--)
        {
            if (up[u][i] != up[v][i])
            {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    vector<int> minimumWeight(vector<vector<int>> &edges,
                              vector<vector<int>> &q)
    {

        int n = edges.size() + 1;

        adj.resize(n);

        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        up.assign(n, vector<int>(max_up + 1));
        distup.assign(n, vector<int>(max_up + 1));
        depth.assign(n, 0);

        dfs(0, 0);

        for (int k = 1; k <= max_up; k++)
        {
            for (int i = 0; i < n; i++)
            {
                int m = up[i][k - 1];
                up[i][k] = up[m][k - 1];
                distup[i][k] = distup[i][k - 1] + distup[m][k - 1];
            }
        }

        vector<int> ans;

        for (auto it : q)
        {

            int x = it[0];
            int y = it[1];
            int z = it[2];

            int cnt = 0;

            int lxy = lca(x, y);
            cnt += distt(x, lxy) + distt(y, lxy);

            int lyz = lca(y, z);
            cnt += distt(y, lyz) + distt(z, lyz);

            int lxz = lca(x, z);
            cnt += distt(x, lxz) + distt(z, lxz);

            ans.push_back(cnt / 2);
        }

        return ans;
    }
};