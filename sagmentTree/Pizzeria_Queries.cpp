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
    void build(int ind, int left, int right, int i, int val)
    {

        if (left == right)
        {
            seg[ind] = val;
            return;
        }

        int mid = ((right - left) >> 1) + left;

        if (i <= mid)
        {
            build(ind * 2 + 1, left, mid, i, val);
        }
        else
        {
            build(ind * 2 + 2, mid + 1, right, i, val);
        }

        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

    int query(int ind, int left, int right, int l, int r)
    {

        if (right < l || r < left)
        {
            return INT_MAX;
        }

        if (l <= left && right <= r)
        {
            return seg[ind];
        }

        int mid = ((right - left) >> 1) + left;

        return min(query(ind * 2 + 1, left, mid, l, r), query(ind * 2 + 2, mid + 1, right, l, r));
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    ST *left = new ST(n);
    ST *right = new ST(n);
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        left->build(0, 0, n - 1, i, ele - i);
        right->build(0, 0, n - 1, i, ele + i);
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i, val;
            cin >> i >> val;
            i--;
            left->build(0, 0, n - 1, i, val - i);
            right->build(0, 0, n - 1, i, val + i);
        }
        else
        {
            int i;
            cin >> i;
            i--;
            int x = left->query(0, 0, n - 1, 0, i) + i;
            int y = right->query(0, 0, n - 1, i, n - 1) - i;
            cout << min(x, y) << "\n";
        }
    }
}