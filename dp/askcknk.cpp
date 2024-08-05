#include <bits/stdc++.h>
using namespace std;

int longest_sequence_tabulation(vector<vector<int>> &dp, string s1, string s2)
{

    for (int i = 0; i <= s1.length(); i++)
        dp[i][0] = 0; // when I2==-1 I1 from -1 to s1.length()-1 is zero
    for (int i = 0; i <= s2.length(); i++)
        dp[0][i] = 0; // when I1==-1 I2 from -1 to s2.length()-1 is zero
    int ans = 0;

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

    if (dp[s1.length()][s2.length()] != s1.length())
    {
        return -1;
    }

    for (int i = 0; i <= s2.length(); i++)
    {
        if (dp[s1.length()][i] == s1.length())
            return i;
    }
}

int main()
{

    string s1 = "abc";
    string s2 = "aecdb";

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

    cout << longest_sequence_tabulation(dp, s1, s2);
}