/*https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B*/

#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> size, parent, maxi, mini;

public:
    DSU(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        maxi.resize(n + 1);
        mini.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            mini[i] = i;
            maxi[i] = i;
        }
    }

    int ultimateParent(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }

        return parent[u] = ultimateParent(parent[u]);
    }

    void unionBySize(int u, int v)
    {

        int ulp_u = ultimateParent(u);
        int ulp_v = ultimateParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            maxi[ulp_u] = max(maxi[ulp_u], maxi[ulp_v]);
            mini[ulp_u] = min(mini[ulp_u], mini[ulp_v]);
        }
        else if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
            maxi[ulp_v] = max(maxi[ulp_u], maxi[ulp_v]);
            mini[ulp_v] = min(mini[ulp_u], mini[ulp_v]);
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            maxi[ulp_u] = max(maxi[ulp_u], maxi[ulp_v]);
            mini[ulp_u] = min(mini[ulp_u], mini[ulp_v]);
        }
    }
    int getMAX(int u)
    {
        return maxi[u];
    }
    int getMIN(int u)
    {
        return mini[u];
    }
    int getSIZE(int u)
    {
        return size[u];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSU *dsu = new DSU(n);
    while (m--)
    {
        string s;
        cin >> s;
        if (s[0] == 'u')
        {
            int u, v;
            cin >> u >> v;
            dsu->unionBySize(u, v);
        }
        else
        {
            int u;
            cin >> u;
            int x1 = dsu->ultimateParent(u);
            int x = dsu->getSIZE(x1);
            int y = dsu->getMAX(x1);
            int z = dsu->getMIN(x1);
            cout << z << " " << y << " " << x << "\n";
        }
    }
}