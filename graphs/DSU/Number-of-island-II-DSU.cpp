#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> rank, parent, size;

public:
    DSU(int n)
    {
        rank.resize(n, 0);
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = findUPar(parent[u]);
    }

    void unionByRank(int u, int v)
    {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool check(int adjr, int adjc, int n, int m)
{

    if (adjr < 0 || adjr >= n || adjc < 0 || adjc > m)
        return false;

    return true;
}

vector<int> numberOfIsland(int n, int m, vector<vector<int>> query)
{

    DSU *node = new DSU(n * m); // 2D node to array node row*m+column
    int count = 0;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    vector<int> ans;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int q = 0; q < query.size(); q++)
    {
        int row = query[q][0];
        int column = query[q][1];
        if (vis[row][column] == 1)
        {
            ans.push_back(count);
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int adjr = row + dr[i];
            int adjc = column + dc[i];
            if (check(adjr, adjc, n, m) == false)
                continue;

            if (vis[adjr][adjc])
            {
                if (node->findUPar(adjr * m + adjc) != node->findUPar(row * m + column))
                {
                    count++;
                    node->unionByRank(row * m + column, adjr * m + adjc);
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}

int main()
{
}
