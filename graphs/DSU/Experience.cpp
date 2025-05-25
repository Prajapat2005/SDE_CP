/*https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C*/

#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<long long> parent, size, points, extra;

public:
    DSU(long long n)
    {
        parent.resize(n + 1);
        for (long long i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        size.resize(n + 1, 1);
        points.resize(n + 1, 0);
        extra.resize(n + 1, 0);
    }

    long long getUParent(long long u)
    {
        if (parent[u] == u)
            return u;

        return getUParent(parent[u]);
    }

    void join(long long u, long long v)
    {
        long long ulp_u = getUParent(u);
        long long ulp_v = getUParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            swap(ulp_u, ulp_v);
        }
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
        extra[ulp_v] = points[ulp_u];
    }

    getpoints(long long u)
    {
        long long num = points[u];
        if (parent[u] == u)
        {
            return num;
        }
        num += getpoints(parent[u]) - extra[u];

        return num;
    }

    void add_points(long long n, long long p)
    {
        long long top = getUParent(n);
        points[top] += p;
    }
};

int main()
{
    long long n;
    long long q;
    cin >> n >> q;
    DSU *dsu = new DSU(n);
    while (q--)
    {
        string type;
        cin >> type;
        if (type == "get")
        {
            long long n;
            cin >> n;
            cout << dsu->getpoints(n) << endl;
        }
        else if (type == "add")
        {
            long long n;
            long long points;
            cin >> n >> points;
            dsu->add_points(n, points);
        }
        else if (type == "join")
        {
            long long a;
            long long b;
            cin >> a >> b;
            dsu->join(a, b);
        }
    }
    return 0;
}