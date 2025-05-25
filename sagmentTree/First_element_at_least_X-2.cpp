#include <bits/stdc++.h>
using namespace std;

class SEG
{
private:
    vector<int> bit;

public:
    SEG(int n)
    {
        bit.resize(4 * n + 1);
    }

    void update(int ind, int l, int r, int i, int val)
    {

        if (l == r)
        {
            bit[ind] = val;
            return;
        }

        int mid = ((r - l) >> 1) + l;
        if (i <= mid)
        {
            update(ind * 2 + 1, l, mid, i, val);
        }
        else
        {
            update(ind * 2 + 2, mid + 1, r, i, val);
        }

        bit[ind] = max(bit[ind * 2 + 1], bit[ind * 2 + 2]);
    }

    int query(int ind, int l, int r, int val)
    {

        if (bit[ind] < val)
        {
            return -1;
        }

        if (l == r)
        {
            return l;
        }

        int left = (ind << 1) + 1;
        int right = left + 1;

        int mid = ((r - l) >> 1) + l;

        if (bit[left] >= val)
        {
            return query(ind * 2 + 1, l, mid, val);
        }
        else
        {
            return query(ind * 2 + 2, mid + 1, r, val);
        }
    }
    int rangeQuery(int ind, int l, int r, int val, int min_index)
    {

        if (l == r)
        {
            if (r < min_index || bit[ind] < val)
                return 1000000;
            return l;
        }

        int mid = ((r - l) >> 1) + l;
        int q1 = 1000000, q2 = 1000000;

        if (bit[2 * ind + 1] >= val && mid >= min_index)
        {
            q1 = rangeQuery(2 * ind + 1, l, mid, val, min_index);
            if (q1 == 1000000)
            {
                q2 = rangeQuery(2 * ind + 2, mid + 1, r, val, min_index);
            }
        }
        else
        {
            q2 = rangeQuery(2 * ind + 2, mid + 1, r, val, min_index);
        }
        return min(q1, q2);
    }
};
int main()
{

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    SEG *seg = new SEG(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        seg->update(0, 0, n - 1, i, v[i]);
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i, val;
            cin >> i >> val;
            seg->update(0, 0, n - 1, i, val);
            v[i] = val;
        }
        else
        {
            int val, ind;
            cin >> val >> ind;
            int x = seg->rangeQuery(0, 0, n - 1, val, ind);
            cout << ((x == 1000000) ? (-1) : (x)) << "\n";
        }
    }

    return 0;
}