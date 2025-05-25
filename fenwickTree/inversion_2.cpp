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
        int num = i;
        while (num < bit.size())
        {
            bit[num] += val;
            num = num + (num & ((-1) * num));
        }
    }

    int pref(int i)
    {
        int num = i;
        int sum = 0;
        while (num)
        {
            sum += bit[num];
            num = num - (num & ((-1) * num));
        }
        return sum;
    }

    int query(int i, int j)
    {
        return pref(j) - pref(i);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    sparse *sp = new sparse(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sp->update(i + 1, 1); // count frequency
    }

    vector<int> z(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int l = 1, r = n;
        int ans;
        // left most suffix sum matching
        while (l <= r)
        {
            int mid = (r - l) / 2 + l;
            int suffSUM = sp->query(mid, n);
            if (suffSUM < v[i])
            {
                r = mid - 1;
            }
            else if (suffSUM > v[i])
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        sp->update(ans, -1);
        z[i] = ans;
    }
    for (auto it : z)
    {
        cout << it << " ";
    }
}