#include <bits/stdc++.h>
using namespace std;

class ST
{
private:
    vector<vector<int>> seg;

public:
    ST(int n)
    {
        seg.resize(4 * n + 1);
    }

    vector<int> merg(vector<int> &v1, vector<int> &v2)
    {

        int n = v1.size();
        int m = v2.size();
        vector<int> ans(n + m);

        int i = 0, j = 0;

        int k = 0;

        while (i < n && j < m)
        {
            if (v1[i] <= v2[j])
            {
                ans[k++] = v1[i++];
            }
            else
            {
                ans[k++] = v2[j++];
            }
        }

        while (i < n)
        {
            ans[k++] = v1[i++];
        }

        while (j < m)
        {
            ans[k++] = v2[j++];
        }

        return ans;
    }

    void update(int ind, int left, int right, int val, int i)
    {

        if (left == right)
        {
            seg[ind] = {val};
            return;
        }

        int mid = (right - left) / 2 + left;

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

    vector<int> query(int ind, int l, int r, int left, int right)
    {

        if (right < l || r < left)
        {
            return {};
        }

        if (l <= left && right <= r)
        {
            return seg[ind];
        }

        int mid = (right - left) / 2 + left;

        vector<int> v1 = query(ind * 2 + 1, l, r, left, mid);
        vector<int> v2 = query(ind * 2 + 2, l, r, mid + 1, right);

        return merg(v1, v2);
    }
};

int binary(vector<int> v, int x)
{

    int l = 0, r = v.size() - 1;

    int ans = -1;

    while (l <= r)
    {
        int mid = (r - l) / 2 + l;

        if (v[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
            ans = mid;
        }
    }
    return (ans + 1);
}

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
            int i, h;
            cin >> i >> h;
            seg->update(0, 0, n - 1, h, i);
        }
        else
        {
            int l, r, p;
            cin >> l >> r >> p;
            vector<int> v = seg->query(0, l, r - 1, 0, n - 1);
            cout << binary(v, p) << "\n";
        }
    }
}