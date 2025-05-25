#include <bits/stdc++.h>
using namespace std;

class ST
{
private:
    vector<int> seg;

public:
    ST(int n)
    {
        seg.resize(4 * n + 1);
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

        seg[ind] = max(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

    int query(int ind, int left, int right, int val)
    {
        if (seg[ind] < val)
        {
            return 0;
        }

        if (left == right)
        {
            seg[ind] -= val;
            return left + 1;
        }

        int mid = ((right - left) >> 1) + left;

        int x = 0, y = 0;
        if (seg[ind * 2 + 1] >= val)
        {
            x = query(ind * 2 + 1, left, mid, val);
        }
        else
        {
            y = query(ind * 2 + 2, mid + 1, right, val);
        }

        seg[ind] = max(seg[ind * 2 + 1], seg[ind * 2 + 2]);

        return max(x, y);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    ST *seg = new ST(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        seg->build(0, 0, n - 1, i, x);
    }
    while (m--)
    {
        int val;
        cin >> val;
        cout << seg->query(0, 0, n - 1, val) << " ";
    }
}