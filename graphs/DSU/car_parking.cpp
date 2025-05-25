/*https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B*/

#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    int n;

public:
    DSU(int n)
    {
        this->n = n + 1;
        parent.resize(n + 2, -1);
    }

    int ultimateParent(int u)
    {
        if (parent[u] == -1)
        {
            if (u == n)
            {
                return ultimateParent(parent[1]);
            }
            return u;
        }
        return parent[u] = ultimateParent(parent[u]);
    }

    void unionBySize(int u, int v)
    {
        if (v == n)
            v = 1;
        int ulp_u = ultimateParent(u);
        int ulp_v = ultimateParent(v);

        if (ulp_u == ulp_v)
            return;

        parent[ulp_u] = ulp_v;
    }
};

int main()
{
    int n;
    std::cin >> n;
    DSU *dsu = new DSU(n);
    while (n--)
    {
        int val;
        std::cin >> val;
        int x = dsu->ultimateParent(val);
        std::cout << x << " ";
        dsu->unionBySize(x, x + 1);
    }
}

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();