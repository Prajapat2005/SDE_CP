/*https://codeforces.com/contest/2005/problem/C*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(char &ch)
{
    return (ch == 'n' || ch == 'a' || ch == 'r' || ch == 'e' || ch == 'k');
}

int solve(int i, vector<string> &v, int j, string &s, vector<vector<int>> &dp)
{

    if (i == v.size())
    {
        return (-1) * 2 * (j);
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int not_take = solve(i + 1, v, j, s, dp);
    int take = 0, ind = j;

    for (int z = 0; z < v[i].length(); z++)
    {
        if (v[i][z] == s[ind])
        {
            ind++;
            take++;
            ind = ind % 5;
        }
        else if (check(v[i][z]))
        {
            take--;
        }
    }
    take += solve(i + 1, v, ind, s, dp);
    return dp[i][j] = max(take, not_take);
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        string s = "narek";

        vector<vector<int>> dp(n + 1, vector<int>(5, -1));

        cout << solve(0, v, 0, s, dp) << "\n";
    }
    return 0;
}