/*https://codeforces.com/contest/2027/problem/D1*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int k, int i, vector<int> &pref, vector<int> &b, vector<vector<int>> &dp)
{

    if (i == pref.size())
        return 0;

    if (k >= b.size())
        return INT_MAX;

    if (dp[i][k] != -1)
        return dp[i][k];

    int ind = upper_bound(pref.begin(), pref.end(), pref[i - 1] + b[k]) - pref.begin();

    if (ind == i)
        return INT_MAX;

    return dp[i][k] = min(solve(k, ind, pref, b, dp) + b.size() - k - 1, solve(k + 1, i, pref, b, dp));
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v1(n + 1, 0);
        vector<int> v2(m);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int ele;
            cin >> ele;
            sum += ele;
            v1[i] = sum;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> v2[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int x = solve(0, 1, v1, v2, dp);

        cout << (x == INT_MAX ? -1 : x) << "\n";
    }
}