#include <bits/stdc++.h>
using namespace std;

string longest_sequence_tabulation(string s1, string s2)
{

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans;

    int i = s1.length(), j = s2.length();

    while (i > 0 && j > 0)
    {

        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
        }
        else
        {
            ans.push_back(s2[j - 1]);
            j--;
        }
    }

    while (i > 0)
    {
        ans.push_back(s1[i - 1]);
        i--;
    }

    while (j > 0)
    {
        ans.push_back(s2[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
string shortestCommonSupersequence(string s1, string s2)
{
    return longest_sequence_tabulation(s1, s2);
}