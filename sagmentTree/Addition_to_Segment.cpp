#include <bits/stdc++.h>
using namespace std;

class ST
{
private:
    vector<long long> seg;

public:
    ST(long long n)
    {
        seg.resize(4 * n + 1, 0);
    }

    void update(long long ind, long long l, long long r, long long left, long long right, long long val)
    {

        if (right < l || r < left)
            return;

        if (l <= left && right <= r)
        {
            seg[ind] += val;
            return;
        }

        long long mid = (right - left) / 2 + left;

        update(ind * 2 + 1, l, r, left, mid, val);
        update(ind * 2 + 2, l, r, mid + 1, right, val);
    }

    long long query(long long ind, long long left, long long right, long long i)
    {

        if (left == right)
        {
            return seg[ind];
        }

        long long mid = (right - left) / 2 + left;

        if (i <= mid)
        {
            return seg[ind] + query(ind * 2 + 1, left, mid, i);
        }
        else
        {
            return seg[ind] + query(ind * 2 + 2, mid + 1, right, i);
        }
    }
};

int main()
{

    long long n, q;
    cin >> n >> q;
    ST *seg = new ST(n);
    while (q--)
    {
        long long type;
        cin >> type;
        if (type == 1)
        {
            long long l, r, val;
            cin >> l >> r >> val;
            seg->update(0, l, r - 1, 0, n - 1, val);
        }
        else
        {
            long long i;
            cin >> i;
            cout << seg->query(0, 0, n - 1, i) << "\n";
        }
    }
}