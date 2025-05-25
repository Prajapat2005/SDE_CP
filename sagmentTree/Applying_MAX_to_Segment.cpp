#include <bits/stdc++.h>
using namespace std;

class ST
{
private:
    vector<int> seg;

public:
    ST(int n)
    {
        seg.resize(4 * n + 1, 0);
    }
    void update(int ind, int l, int r, int left, int right, int val)
    {

        if (right < l || r < left)
            return;

        if (l <= left && right <= r)
        {
            seg[ind] = max(seg[ind], val);
            return;
        }

        int mid = (right - left) / 2 + left;

        update(ind * 2 + 1, l, r, left, mid, val);
        update(ind * 2 + 2, l, r, mid + 1, right, val);
    }

    int query(int ind, int left, int right, int i)
    {

        if (left == right)
        {
            return seg[ind];
        }

        int mid = (right - left) / 2 + left;
        int x = 0, y = 0;
        if (i <= mid)
        {
            x = max(seg[ind], query(ind * 2 + 1, left, mid, i));
        }
        else
        {
            y = max(seg[ind], query(ind * 2 + 2, mid + 1, right, i));
        }
        return max(x, y);
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
            seg->update(0, l, r - 1, 0, n - 1, val);
        }
        else
        {
            int i;
            cin >> i;
            cout << seg->query(0, 0, n - 1, i) << "\n";
        }
    }
}