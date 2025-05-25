#include <bits/stdc++.h>
using namespace std;

class ST
{
private:
    vector<int> /* seg, */ lazy;

public:
    ST(int n)
    {
        /* seg.resize(4 * n + 1, -1); */
        lazy.resize(4 * n + 1, -1);
    }

    void update(int ind, int left, int right, int l, int r, int val)
    {
        if (lazy[ind] != -1)
        {
            /* seg[ind] = lazy[ind]; */

            if (left != right)
            {
                lazy[ind * 2 + 1] = lazy[ind];
                lazy[ind * 2 + 2] = lazy[ind];
                lazy[ind] = -1;
            }
        }

        if (right < l || left > r)
        {
            return;
        }

        if (left >= l && right <= r)
        {
            lazy[ind] = val;
            return;
        }

        int mid = (left + right) / 2;
        update(ind * 2 + 1, left, mid, l, r, val);
        update(ind * 2 + 2, mid + 1, right, l, r, val);
    }

    // Point query with lazy propagation
    int query(int ind, int left, int right, int i)
    {
        if (lazy[ind] != -1)
        {
            /* seg[ind] = lazy[ind]; */

            if (left != right)
            {
                lazy[ind * 2 + 1] = lazy[ind];
                lazy[ind * 2 + 2] = lazy[ind];
                lazy[ind] = -1;
            }
        }

        if (left == right)
        {
            return lazy[ind];
        }

        int mid = (left + right) / 2;
        if (i <= mid)
        {
            return query(ind * 2 + 1, left, mid, i);
        }
        else
        {
            return query(ind * 2 + 2, mid + 1, right, i);
        }
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    ST *seg = new ST(n);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r, val;
            cin >> l >> r >> val;
            seg->update(0, 0, n - 1, l, r - 1, val);
        }
        else if (type == 2)
        {
            int i;
            cin >> i;
            int x = seg->query(0, 0, n - 1, i);
            cout << ((x == -1) ? (0) : (x)) << "\n";
        }
    }

    return 0;
}
