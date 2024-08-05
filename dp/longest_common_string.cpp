#include <bits/stdc++.h>
using namespace std;

// tabulation
int longest_string_tabulation(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= s1.length(); i++)
        dp[i][0] = 0; // when I2==-1 I1 from -1 to s1.length()-1 is zero
    for (int i = 0; i <= s2.length(); i++)
        dp[0][i] = 0; // when I1==-1 I2 from -1 to s2.length()-1 is zero

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0; // Characters don't match, substring length becomes 0
        }
    }

    return ans;
}

// i-1 term is there means we can obtimize space
// space obtimization
int longest_string_tabulation_2(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<int> pre(s2.length() + 1, 0); // when I1==-1 I2 from -1 to s2.length()-1 is zero

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {

        vector<int> curr(s2.length() + 1, 0); // 0th index of every row is zero because I2==-1

        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int val = 1 + pre[j - 1]; // Characters match, increment substring length
                curr[j] = val;            // Update the DP table
                ans = max(ans, val);      // Update the maximum substring length found so far
            }
            else
                curr[j] = 0; // Characters don't match, substring length becomes 0
        }

        pre = curr;
    }

    return ans;
}

int main()
{
    string s1 = "edcba", s2 = "aedcbbaa";
    cout << longest_string_tabulation_2(s1, s2);
    return 0;
}