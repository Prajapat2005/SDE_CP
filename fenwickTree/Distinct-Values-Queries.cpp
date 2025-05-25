/* https://cses.fi/problemset/task/1734/ */

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

    void update(int i, int val)
    {
        int num = i + 1;
        while (num < bit.size())
        {
            bit[num] += val;
            num = num + (num & (-num));
        }
    }

    int pref(int i)
    {
        int num = i + 1;
        int sum = 0;
        while (num)
        {
            sum = sum + bit[num];
            num = num - (num & (-num));
        }
        return sum;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<pair<int, int>>> query(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        query[a].push_back({b, i});
    }

    Fenwick *fen = new Fenwick(n);
    map<int, int> last_index;
    vector<int> ans(m);

    for (int i = n - 1; i >= 0; i--)
    {
        int val = v[i];

        if (last_index.count(val))
        {
            fen->update(last_index[val], -1);
        }

        last_index[val] = i;
        fen->update(i, 1);

        for (auto qr : query[i])
        {
            ans[qr.second] = fen->pref(qr.first);
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << "\n";
    }
}