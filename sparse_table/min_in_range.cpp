#include <bits/stdc++.h>
using namespace std;

class Sparse
{
private:
    vector<vector<int>> sp;
    int MAXK;

public:
    Sparse(int n)
    {
        MAXK = log2(n);
        sp.resize(n, vector<int>(MAXK + 1, INT_MAX));
    }

    void build(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            sp[i][0] = v[i];
        }

        for (int k = 1; k <= MAXK; k++)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (i + (1 << (k - 1)) >= v.size())
                    break;
                sp[i][k] = min(sp[i][k - 1], sp[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    int query(int l, int r)
    {

        int len = r - l + 1;
        int k = 0;
        while ((1 << (k + 1)) <= len)
        {
            k++;
        }

        return min(sp[l][k], sp[r - (1 << k) + 1][k]);
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
    Sparse *sp = new Sparse(n);
    sp->build(v);
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        cout << (sp->query(i, j)) << "\n";
    }
}