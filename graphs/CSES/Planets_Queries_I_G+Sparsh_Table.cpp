#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXK = log2(1000000000);

// graph + sparsh table

int32_t main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> sparsh(200001, vector<int>(MAXK + 1));

    for (int i = 1; i <= n; i++)
    {
        int ele;
        cin >> ele;
        sparsh[i][0] = ele;
    }

    for (int k = 1; k <= MAXK; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            sparsh[i][k] = sparsh[sparsh[i][k - 1]][k - 1];
        }
    }

    while (q--)
    {
        int node, dis;
        cin >> node >> dis;

        /* for (int k = MAXK; k >= 0; k--)
        {
            if ((1 << k) <= dis)
            {
                dis -= (1 << k);
                node = sparsh[node][k];
            }
        } */

        for (int k = 0; k <= MAXK; k++)
        {
            if (dis & (1ll << k))
            {
                node = sparsh[node][k];
            }
        }

        cout << node << "\n";
    }
}