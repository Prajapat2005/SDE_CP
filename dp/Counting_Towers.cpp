// https://cses.fi/problemset/task/2413
// IMP
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        /* vector<int> type1(n + 1);
        vector<int> type2(n + 1);
        type1[1] = 1; // |   |
        type2[1] = 1; // | | |

        int mod = 1e9 + 7;

        for (int i = 2; i <= n; i++)
        {
            type1[i] = (2 * type1[i - 1] + type2[i - 1]) % mod;
            type2[i] = (4 * type2[i - 1] + type1[i - 1]) % mod;
        }

        cout << (type1[n] + type2[n]) % mod << "\n"; */

        int t1_pre = 1;
        int t2_pre = 1;

        int mod = 1e9 + 7;

        for (int i = 2; i <= n; i++)
        {
            int t1_curr = (2 * t1_pre + t2_pre) % mod;
            int t2_curr = (4 * t2_pre + t1_pre) % mod;
            t1_pre = t1_curr;
            t2_pre = t2_curr;
        }

        cout << (t1_pre + t2_pre) % mod << '\n';
    }
}