/*https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B*/

#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, maxi;

public:
    DSU(int n)
    {
        parent.resize(n + 2, -1);
        /* maxi.resize(n + 2);
        for (int i = 1; i <= n + 1; i++)
        {
            maxi[i] = i;
        } */
    }

    int ultimateParent(int u)
    {
        if (parent[u] == -1)
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

        parent[ulp_u] = ulp_v;
        /*  maxi[ulp_u] = std::max(maxi[ulp_u], maxi[ulp_v]); */
    }

    int findRIGHT(int n)
    {
        return maxi[ultimateParent(n)];
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    DSU *dsu = new DSU(n);
    while (m--)
    {
        char ch;
        std::cin >> ch;
        if (ch == '-')
        {
            int val;
            std::cin >> val;
            dsu->unionBySize(val, val + 1);
        }
        else
        {
            int val;
            std::cin >> val;
            int x = dsu->ultimateParent(val);
            std::cout << ((x == n + 1) ? (-1) : (x)) << "\n";
        }
    }
}

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();