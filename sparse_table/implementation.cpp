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
        sp.resize(n, vector<int>(MAXK + 1, 0));
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
                sp[i][k] = sp[i][k - 1] + sp[i + (1 << (k - 1))][k - 1];
            }
        }
    }

    int query(int l, int r)
    {
        int len = r - l + 1;
        int sum = 0;
        for (int k = 25; k >= 0; k--)
        {
            if ((1 << k) <= len)
            {
                sum += sp[l][k];
                l += (1 << k);
                len = r - l + 1;
            }
            if (len == 0)
                break;
        }

        return sum;
    }
};

// min implementation
class idempotentSparse
{
private:
    vector<vector<int>> sp;
    int MAXK;
    vector<int> lg;

public:
    idempotentSparse(int n)
    {
        MAXK = log2(n);
        sp.resize(n, vector<int>(MAXK + 1, 0));
        // precompute log also
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            lg[i] = lg[i / 2] + 1;
        }
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
        int k = lg[len];
        return min(sp[l][k], sp[r - (1 << k) + 1][k]);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    idempotentSparse *st = new idempotentSparse(10);

    st->build(v);

    cout << (st->query(0, 7)) << "\n";
    return 0;
}