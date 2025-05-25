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
    void build(int ind, int left, int right, vector<int> v, bool flag)
    {
        if (right == left)
        {
            seg[ind] = v[left];
            return;
        }

        int mid = (right + left) >> 1;
        build(ind * 2 + 1, left, mid, v, !flag);
        build(ind * 2 + 2, mid + 1, right, v, !flag);

        if (flag)
        {
            seg[ind] = seg[ind * 2 + 1] | seg[ind * 2 + 2];
        }
        else
        {
            seg[ind] = seg[ind * 2 + 1] ^ seg[ind * 2 + 2];
        }
    }
    void update(int ind, int left, int right, int i, int val, bool flag)
    {
        if (right == left)
        {
            seg[ind] = val;
            return;
        }

        int mid = (right + left) >> 1;
        if (i <= mid)
        {
            update(ind * 2 + 1, left, mid, i, val, !flag);
        }
        else
        {
            update(ind * 2 + 2, mid + 1, right, i, val, !flag);
        }

        if (flag)
        {
            seg[ind] = seg[ind * 2 + 1] | seg[ind * 2 + 2];
        }
        else
        {
            seg[ind] = seg[ind * 2 + 1] ^ seg[ind * 2 + 2];
        }
    }
    int getAns()
    {
        return seg[0];
    }
};
int main()
{

    int n, q;
    cin >> n >> q;
    int ele = n;
    n = (1 << n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    SEGtree *t1 = new SEGtree(n);

    if (ele & 1)
    {
        t1->build(0, 0, n - 1, v, true);
    }
    else
    {
        t1->build(0, 0, n - 1, v, false);
    }

    while (q--)
    {
        int i, val;
        cin >> i >> val;

        i--;

        if (ele & 1)
        {
            t1->update(0, 0, n - 1, i, val, true);
        }
        else
        {
            t1->update(0, 0, n - 1, i, val, false);
        }

        v[i] = val;
        cout << t1->getAns() << "\n";
    }
    return 0;
}