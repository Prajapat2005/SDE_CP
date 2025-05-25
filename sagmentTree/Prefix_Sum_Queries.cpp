#include <bits/stdc++.h>
using namespace std;

class ST
{
    struct Node
    {
        long long max_pref;
        long long sum;
    };

private:
    vector<Node> seg;

public:
    ST(long long n)
    {
        seg.resize(4 * n + 1);
    }

    Node merg(Node n1, Node n2)
    {
        Node ans;
        ans.sum = n1.sum + n2.sum;
        ans.max_pref = max(n1.max_pref, n1.sum + n2.max_pref);
        return ans;
    }

    Node null()
    {
        Node temp;
        temp.max_pref = INT_MIN;
        temp.sum = 0;
        return temp;
    }

    void update(long long ind, long long left, long long right, long long val, long long i)
    {

        if (left == right)
        {
            seg[ind].sum = val;
            seg[ind].max_pref = val;
            return;
        }

        long long mid = ((right - left) >> 1) + left;
        if (i <= mid)
        {
            update(ind * 2 + 1, left, mid, val, i);
        }
        else
        {
            update(ind * 2 + 2, mid + 1, right, val, i);
        }
        seg[ind] = merg(seg[ind * 2 + 1], seg[ind * 2 + 2]);
    }

    Node query(long long ind, long long left, long long right, long long l, long long r)
    {

        if (right < l || r < left)
        {
            return null();
        }

        if (l <= left && right <= r)
        {
            return seg[ind];
        }

        long long mid = ((right - left) >> 1) + left;
        return merg(query(ind * 2 + 1, left, mid, l, r), query(ind * 2 + 2, mid + 1, right, l, r));
    }
};

int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> v(n);
    ST *seg = new ST(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
        seg->update(0, 0, n - 1, v[i], i);
    }
    while (q--)
    {
        long long type;
        cin >> type;
        if (type == 1)
        {
            long long k, u;
            cin >> k >> u;
            seg->update(0, 0, n - 1, u, k - 1);
        }
        else
        {
            long long l, r;
            cin >> l >> r;
            long long x = seg->query(0, 0, n - 1, l - 1, r - 1).max_pref;
            cout << ((x < 0) ? (0) : (x)) << "\n";
        }
    }
}