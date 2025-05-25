#include <bits/stdc++.h>
using namespace std;

class Fenwick
{
private:
    vector<int> bit;

public:
    Fenwick(int n)
    {
        bit.resize(n + 1, 0);
    }

    // v[i]+=val
    void update(int i, int val)
    {
        int num = i; // one base indexing

        while (num < bit.size())
        {
            bit[num] += val;
            num = num + (num & ((-1) * num));
        }
    }

    int pref(int l)
    {
        int num = l;
        int ans = 0;
        while (num)
        {
            ans = ans + bit[num];
            num = num - (num & ((-1) * num));
        }
        return ans;
    }

    int query(int l, int r)
    {
        return pref(r) - pref(l);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    Fenwick *f = new Fenwick(maxi);
    int count = 0;
    // first add then count number of element which is geater than curr element
    for (int i = 0; i < n; i++)
    {
        f->update(v[i], 1);
        count += (f->query(v[i], maxi));
    }
    cout << count;
}