#include <bits/stdc++.h>
using namespace std;

class Fenwick
{
private:
    vector<int> bit;

public:
    Fenwick(int n)
    {
        bit.resize(n + 1, 0);
    }

    void build(vector<int> v)
    {

        for (int i = 0; i < v.size(); i++)
        {
            int num = i + 1; // one base indexing

            while (num <= v.size())
            {
                bit[num] += v[i];
                num = num + (num & ((-1) * num));
            }
        }
    }

    // v[i]+=val
    void update(int i, int val)
    {
        int num = i + 1; // one base indexing

        while (num < bit.size())
        {
            bit[num] += val;
            num = num + (num & ((-1) * num));
        }
    }

    int pref(int l)
    {
        int num = l + 1;
        int ans = 0;
        while (num)
        {
            ans = ans + bit[num];
            num = num - (num & ((-1) * num));
        }
        return ans;
    }

    int query(int l, int r)
    {
        return pref(r) - pref(l - 1);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Fenwick *f = new Fenwick(n);
    f->build(v);
    while (q--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 1)
        {
            m--;
            f->update(m, k - v[m]);
            v[m] = k;
        }
        else
        {
            m--;
            k--;
            cout << f->query(m, k) << "\n";
        }
    }
}