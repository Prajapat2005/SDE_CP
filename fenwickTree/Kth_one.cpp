#include <bits/stdc++.h>
using namespace std;
class sparse
{
private:
    vector<int> bit;

public:
    sparse(int n)
    {
        bit.resize(n + 1, 0);
    }

    void update(int i, int val)
    {
        int ind = i + 1;
        while (ind < bit.size())
        {
            bit[ind] += val;
            ind = ind + (ind & ((-1) * ind));
        }
    }
    int pref(int i)
    {
        int ind = i;
        int sum = 0;
        while (ind)
        {
            sum = sum + bit[ind];
            ind = ind - (ind & ((-1) * ind));
        }
        return sum;
    }
};
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    sparse *sp = new sparse(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sp->update(i, v[i]);
    }
    while (q--)
    {
        int op, k;
        cin >> op >> k;
        if (op == 1)
        {
            if (v[k] == 0)
            {
                sp->update(k, 1);
                v[k] = 1;
            }
            else
            {
                sp->update(k, -1);
                v[k] = 0;
            }
        }
        else
        {
            int l = 1, r = n;
            while (l < r)
            {
                int mid = (r - l) / 2 + l;
                int sum = sp->pref(mid);
                if (sum < k + 1)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }

            cout << l - 1 << "\n";
        }
    }
    return 0;
}