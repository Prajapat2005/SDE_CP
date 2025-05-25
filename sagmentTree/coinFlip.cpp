#include <bits/stdc++.h>
using namespace std;

class SEGtree
{
private:
    vector<int> seg, lazy;

public:
    SEGtree(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
    void build(int ind, int left, int right, vector<int> v)
    {

        if (left == right)
        {
            seg[ind] = v[left];
            return;
        }
        int mid = (left + right) >> 1;
        build(ind * 2 + 1, left, mid, v);
        build(ind * 2 + 2, mid + 1, right, v);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
    void update(int ind, int left, int right, int l, int r)
    {
        // update previous remaining update ans propogate downwords
        if (lazy[ind] != 0)
        {
            seg[ind] = (right - left + 1) - seg[ind];
            if (right != left)
            {
                lazy[ind * 2 + 1] = !lazy[ind * 2 + 1];
                lazy[ind * 2 + 2] = !lazy[ind * 2 + 2];
            }
            lazy[ind] = 0;
        }

        if (right < l || r < left)
        {
            return;
        }
        if (l >= left && right <= r)
        {
            seg[ind] = (right - left + 1) - seg[ind];
            if (right != left)
            {
                lazy[ind * 2 + 1] = !lazy[ind * 2 + 1];
                lazy[ind * 2 + 2] = !lazy[ind * 2 + 2];
            }
            return;
        }

        int mid = (right + left) >> 1;
        update(ind * 2 + 1, left, mid, l, r);
        update(ind * 2 + 2, mid + 1, right, l, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
    int query(int ind, int left, int right, int l, int r)
    {

        // update previous remaining update ans propogate downwords
        if (lazy[ind] != 0)
        {
            seg[ind] = (right - left + 1) - seg[ind];
            if (right != left)
            {
                lazy[ind * 2 + 1] = !lazy[ind * 2 + 1];
                lazy[ind * 2 + 2] = !lazy[ind * 2 + 2];
            }
            lazy[ind] = 0;
        }

        // no overlap
        if (right < l || r < left)
        {
            return 0;
        }

        // complete overlap
        if (l >= left && right <= r)
        {
            return seg[ind];
        }

        // partial
        int mid = (right - left) / 2 + left;
        int x = query(ind * 2 + 1, left, mid, l, r);
        int y = query(ind * 2 + 2, mid + 1, right, l, r);

        return x + y;
    }
};
int main()
{
}