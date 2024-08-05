#include <bits/stdc++.h>
using namespace std;

bool isAllStars(string &S1, int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (S1[j] != '*')
            return false;
    }
    return true;
}
bool ans(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{

    if (i < 0 && j < 0)
        return true;
    if (j < 0 && i >= 0)
        return false;
    if (i < 0 && j >= 0)
        return isAllStars(s2, j);

    if (dp[i + 1][j + 1] != -1)
        return dp[i + 1][j + 1];

    if (s1[i] == s2[j] || s2[j] == '?')
    {
        return dp[i + 1][j + 1] = ans(s1, s2, i - 1, j - 1, dp);
    }
    else if (s2[j] == '*')
    {
        return dp[i + 1][j + 1] = ans(s1, s2, i, j - 1, dp) || ans(s1, s2, i - 1, j, dp);
        // empty or take
    }
    else
    {
        return dp[i + 1][j + 1] = false;
    }
}

int ans2(string s1, string s2)
{

    int n = s1.size();
    int m = s2.size();

    vector<int> pre(m + 1, 0);

    for (int j = 1; j <= m; j++)
    {
        pre[j] = isAllStars(s2, j - 1);
    }

    pre[0] = 1;

    for (int i = 1; i <= n; i++)
    {

        vector<int> curr(m + 1, 0);

        for (int j = 1; j <= m; j++)
        {

            if (s1[i - 1] == s2[j - 1] || s2[j - 1] == '?')
            {
                curr[j] = pre[j - 1];
            }
            else if (s2[j - 1] == '*')
            {
                curr[j] = curr[j - 1] || pre[j]; // empty or take
            }
            else
            {
                curr[j] = false;
            }
        }

        pre = curr;
    }

    return pre[m];
}
bool isMatch(string s1, string s2)
{

    return ans2(s1, s2);
}