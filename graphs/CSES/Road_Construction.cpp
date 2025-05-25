#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int maxi;
    int comp;

public:
    DSU(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);
        size.resize(n, 1);
        maxi = 1;
        comp = n;
    }

    void join(int u, int v)
    {

        int pu = UP(u);
        int pv = UP(v);

        if (pu == pv)
            return;

        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
            maxi = max(maxi, size[pu]);
            comp--;
        }
        else if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
            maxi = max(maxi, size[pv]);
            comp--;
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
            maxi = max(maxi, size[pu]);
            rank[pu]++;
            comp--;
        }
    }

    int UP(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = UP(parent[x]);
    }

    int cmp()
    {
        return this->comp;
    }

    int siz()
    {
        return this->maxi;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    DSU *ds = new DSU(n);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ds->join(u, v);
        cout << (ds->cmp()) << " " << (ds->siz()) << "\n";
    }
}