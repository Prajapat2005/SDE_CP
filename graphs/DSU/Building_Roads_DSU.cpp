/* https://cses.fi/problemset/task/1666 */
#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        rank.resize(n + 1, 0);
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

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    vector<int> totalParent()
    {
        vector<int> ans;
        for (int i = 1; i <= parent.size(); i++)
        {
            if (parent[i] == i)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSU *dsu = new DSU(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        dsu->unionByRank(u, v);
    }
    vector<int> ans = dsu->totalParent();
    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
    return 0;
}