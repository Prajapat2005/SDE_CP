#include <bits/stdc++.h>
using namespace std;

class SEGtree
{
private:
    vector<int> seg;

public:
    SEGtree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int ind, int left, int right, vector<int> v)
    {
        if (left == right)
        {
            seg[ind] = v[left];
            return;
        }

        int mid = (right - left) / 2 + left;
        build(ind * 2 + 1, left, mid, v);
        build(ind * 2 + 2, mid + 1, right, v);

        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

    // {l,r}---> query
    // {left,right}---> segment tree
    int query(int ind, int left, int right, int l, int r)
    {

        // no overlap
        if (right < l || r < left)
        {
            return INT_MAX;
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

        return min(x, y);
    }
    void update(int ind, int left, int right, int i, int val)
    {

        if (left == right)
        {
            seg[ind] = val;
            return;
        }

        int mid = (right - left) / 2 + left;
        if (mid <= i)
        {
            update(ind * 2 + 1, left, mid, i, val);
        }
        else
        {
            update(ind * 2 + 2, mid + 1, right, i, val);
        }

        seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }
};
int main()
{
}