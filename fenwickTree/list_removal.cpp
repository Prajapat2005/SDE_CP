// https://cses.fi/problemset/task/1749
#include <bits/stdc++.h>
using namespace std;

class Fenwick
{
private:
    vector<int> bit;

public:
    Fenwick(int n)
    {
        bit.resize(n, 0);
    }

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
};

int main()
{
    int n;
    cin >> n;
    int q = n;
    vector<int> v(n + 1);
    Fenwick *fen = new Fenwick(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        fen->update(i, 1);
    }
    while (q--)
    {
        int num;
        cin >> num;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            int sum = fen->pref(mid);
            if (sum < num)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        cout << v[l] << " ";
        fen->update(l, -1);
    }
}