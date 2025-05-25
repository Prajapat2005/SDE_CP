#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        size.resize(n + 1, 1);
    }
    int ultimatePARENT(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }

        return parent[u] = ultimatePARENT(parent[u]);
    }
    void join(int u, int v)
    {

        int ulp_u = ultimatePARENT(u);
        int ulp_v = ultimatePARENT(v);

        if (size[ulp_u] < size[ulp_v])
        {
            swap(ulp_u, ulp_v);
        }
        size[ulp_u] += size[ulp_v];
        parent[ulp_v] = ulp_u;
    }
};

int main()
{

    int n, m, z;
    cin >> n >> m >> z;
    DSU *dsu = new DSU(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
    }

    vector<pair<int, pair<int, int>>> q;
    while (z--)
    {
        string type;
        cin >> type;
        if (type == "cut")
        {
            int u, v;
            cin >> u >> v;
            q.push_back({true, {u, v}});
        }
        else
        {
            int u, v;
            cin >> u >> v;
            q.push_back({false, {u, v}});
        }
    }
    vector<bool> ans;
    for (int i = q.size() - 1; i >= 0; i--)
    {
        if (q[i].first)
        {
            dsu->join(q[i].second.first, q[i].second.second);
        }
        else
        {
            ans.push_back(dsu->ultimatePARENT(q[i].second.first) == dsu->ultimatePARENT(q[i].second.second));
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i])
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}