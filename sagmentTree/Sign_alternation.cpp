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

    void update(int ind, int left, int right, int i, int val)
    {

        if (left == right)
        {
            seg[ind] += val;
            return;
        }

        int mid = (right - left) / 2 + left;

        if (i <= mid)
        {
            update(ind * 2 + 1, left, mid, i, val);
        }
        else
        {
            update(ind * 2 + 2, mid + 1, right, i, val);
        }

        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    int query(int ind, int l, int r, int left, int right)
    {

        if (r < left || right < l)
        {
            return 0;
        }

        if (l <= left && right <= r)
        {
            return seg[ind];
        }

        int mid = (right - left) / 2 + left;

        int x1 = query(ind * 2 + 1, l, r, left, mid);
        int x2 = query(ind * 2 + 2, l, r, mid + 1, right);

        return x1 + x2;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    ST *odd = new ST(n);
    ST *even = new ST(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i % 2 != 0)
        {
            odd->update(0, 0, n - 1, i, v[i]);
        }
        else
        {
            even->update(0, 0, n - 1, i, v[i]);
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int i, val;
            cin >> i >> val;
            i--;

            int update = val - v[i];

            if (i % 2 != 0)
            {
                odd->update(0, 0, n - 1, i, update);
            }
            else
            {
                even->update(0, 0, n - 1, i, update);
            }

            v[i] = val;
        }
        else
        {

            int i, j;
            cin >> i >> j;
            i--;
            j--;

            int x1 = odd->query(0, i, j, 0, n - 1);
            int x2 = even->query(0, i, j, 0, n - 1);

            if (i & 1)
            {
                cout << x1 - x2 << "\n";
            }
            else
            {
                cout << x2 - x1 << "\n";
            }
        }
    }
}