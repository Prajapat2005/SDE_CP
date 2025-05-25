#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://cses.fi/problemset/task/1097/
//  IMP

/* int solve(int i, int j, vector<int> v, int f)
{

    if (i > j)
        return 0;

    if (f)
    {
        return max(v[i] + solve(i + 1, j, v, false, dp), v[j] + solve(i, j - 1, v, false, dp));
    }
    else
    {
        return min(solve(i + 1, j, v, true, dp), solve(i, j - 1, v, true, dp));
    }
}*/

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &it : v)
    {
        cin >> it;
    }

    vector<vector<int>> dp(n, vector<int>(n));
    // dp[l][r] = max score of playes 1 between l and r if he playes first

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = v[i];
            }
            else if (j - i == 1)
            {
                dp[i][j] = max(v[i], v[j]);
            }
            else
            {
                dp[i][j] = max(v[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), v[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}
