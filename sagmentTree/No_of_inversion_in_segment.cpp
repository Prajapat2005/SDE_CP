#include <bits/stdc++.h>
using namespace std;

struct item
{
    long long inv_cnt;
    vector<int> freq;

    item()
    {
        freq.resize(41, 0);
        inv_cnt = 0;
    }
};

class ST
{
private:
    vector<item> seg;

public:
    item null()
    {
        item x;
        return x;
    }

    ST(int n)
    {
        seg.resize(4 * n + 1);
    }

    item merge(item left, item right)
    {
        item parent;
        parent.inv_cnt = left.inv_cnt + right.inv_cnt;

        vector<int> prev(41, 0);
        prev[0] = right.freq[0];

        for (int i = 0; i < 41; i++)
        {
            parent.freq[i] = left.freq[i] + right.freq[i];

            if (i != 0)
            {
                parent.inv_cnt += 1LL * left.freq[i] * prev[i - 1];
                prev[i] = prev[i - 1] + right.freq[i];
            }
        }

        return parent;
    }

    void build(int ind, int left, int right, vector<int> v)
    {
        if (left == right)
        {
            seg[ind].inv_cnt = 0;
            seg[ind].freq[v[left]] = 1;
            return;
        }

        int mid = (right - left) / 2 + left;

        build(ind * 2 + 1, left, mid, v);
        build(ind * 2 + 2, mid + 1, right, v);

        seg[ind] = merge(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

    void update(int ind, int left, int right, int i, int val, int prev)
    {
        if (left == right)
        {
            seg[ind].freq[prev] = 0;
            seg[ind].freq[val] = 1;
            return;
        }

        int mid = (right - left) / 2 + left;

        if (i <= mid)
        {
            update(ind * 2 + 1, left, mid, i, val, prev);
        }
        else
        {
            update(ind * 2 + 2, mid + 1, right, i, val, prev);
        }

        seg[ind] = merge(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

    item query(int ind, int l, int r, int left, int right)
    {
        if (right < l || r < left)
            return null();

        if (l <= left && right <= r)
            return seg[ind];

        int mid = (right - left) / 2 + left;

        item x = query(ind * 2 + 1, l, r, left, mid);
        item y = query(ind * 2 + 2, l, r, mid + 1, right);

        return merge(x, y);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ST *seg = new ST(n);
    seg->build(0, 0, n - 1, v);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            item x = seg->query(0, i, j, 0, n - 1);
            cout << x.inv_cnt << "\n";
        }
        else
        {
            int i, val;
            cin >> i >> val;
            i--;
            seg->update(0, 0, n - 1, i, val, v[i]);
            v[i] = val;
        }
    }

    return 0;
}
