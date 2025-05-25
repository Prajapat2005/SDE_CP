#include <bits/stdc++.h>
using namespace std;

class SEG
{
    struct data
    {
        long long msum;
        long long pref;
        long long suff;
        long long sum;
    };

private:
    vector<data> seg;

public:
    SEG(long long n)
    {
        seg.resize(4 * n + 1);
    }

    void combine(long long n)
    {

        seg[n].pref = max(seg[2 * n + 1].pref, seg[2 * n + 1].sum + seg[2 * n + 2].pref);
        seg[n].suff = max(seg[2 * n + 2].suff, seg[2 * n + 1].suff + seg[2 * n + 2].sum);
        seg[n].msum = max(seg[2 * n + 1].msum, max(seg[2 * n + 2].msum, seg[2 * n + 1].suff + seg[2 * n + 2].pref));
        seg[n].sum = seg[2 * n + 1].sum + seg[2 * n + 2].sum;
    }

    long long maxi()
    {
        return ((seg[0].msum <= -1) ? (0) : (seg[0].msum));
    }

    void update(long long ind, long long l, long long r, long long i, long long val)
    {

        if (l == r)
        {
            seg[ind].sum = val;
            seg[ind].msum = val;
            seg[ind].pref = val;
            seg[ind].suff = val;
            return;
        }

        long long mid = ((r - l) >> 1) + l;

        if (i <= mid)
        {
            update(ind * 2 + 1, l, mid, i, val);
        }
        else
        {
            update(ind * 2 + 2, mid + 1, r, i, val);
        }
        combine(ind);
    }
};

int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> v(n);
    SEG *seg = new SEG(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
        seg->update(0, 0, n - 1, i, v[i]);
    }

    cout << seg->maxi() << "\n";
    while (q--)
    {
        long long i, val;
        cin >> i >> val;
        seg->update(0, 0, n - 1, i, val);
        v[i] = val;
        cout << seg->maxi() << "\n";
    }
    return 0;
}
