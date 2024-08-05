#include <bits/stdc++.h>
using namespace std;

int longest_subsequence(string s1, string s2, int index1, int index2)
{
    if (index1 == 0 || index2 == 0)
    {
        if (s1[index1] == s2[index2])
            return 1;
        else
            return 0;
    }

    if (s1[index1] == s2[index2])
    {
        return 1 + longest_subsequence(s1, s2, index1 - 1, index2 - 1);
        }
    // if equal means subsequence of length 1 is found and then find another sequence in I1-1 and I2-1

    if (s1[index1] != s2[index2])
    {
        // if not found then take both possibility I1-1,I2 and I1,I2-1 and take max of both

        int p1 = longest_subsequence(s1, s2, index1 - 1, index2);
        int p2 = longest_subsequence(s1, s2, index1, index2 - 1);
        return max(p1, p2);
    }
}

// using dp reduce ovelaping subproblem
int longest_subsequence_dp(vector<vector<int>> dp, string s1, string s2, int index1, int index2)
{

    if (s1[index1] == s2[index2])
    {
        if (index1 > 0 && index2 > 0)
        {

            if (dp[index1 - 1][index2 - 1] == -1)
                dp[index1 - 1][index2 - 1] = longest_subsequence_dp(dp, s1, s2, index1 - 1, index2 - 1);
            return 1 + dp[index1 - 1][index2 - 1];
        }
        else
            return 1;
    }
    // if equal means subsequence of length 1 is found and then find another sequence in I1-1 and I2-1

    if (s1[index1] != s2[index2])
    {
        int p1 = 0, p2 = 0;
        if (index1 > 0)
        {
            if (dp[index1 - 1][index2] == -1)
                dp[index1 - 1][index2] = longest_subsequence_dp(dp, s1, s2, index1 - 1, index2);
            p1 = dp[index1 - 1][index2];
        }

        if (index2 > 0)
        {
            if (dp[index1][index2 - 1] == -1)
                dp[index1][index2 - 1] = longest_subsequence_dp(dp, s1, s2, index1, index2 - 1);
            p2 = dp[index1][index2 - 1];
        }

        // if not found then take both possibility I1-1,I2 and I1,I2-1 and take max of both
        return max(p1, p2);
    }
}
// tabulation
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
    return dp[s1.length()][s2.length()];
}

// i-1 term is there means we can obtimize space
// space obtimization
int longest_sequence_dp_2(string s1, string s2)
{

    vector<int> pre(s2.length() + 1, 0); // when I1==-1 I2 from -1 to s2.length()-1 is zero

    // 0th index of every row is zero because I2==-1
    int ans = 0;
    for (int i = 1; i <= s1.length(); i++)
    {
        vector<int> curr(s2.length() + 1, 0);

        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + pre[j - 1];
            }
            else
            {
                curr[j] = 0 + max(pre[j], curr[j - 1]);
            }
        }
        pre = curr;
    }

    return pre[s2.length()];
}

// print string
string ans(vector<vector<int>> dp, int i, int j, string s1, string s2)
{
    string s;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(s.begin(), s.end());
    return s;
}

vector<vector<int>> longest_sequence_dp(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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

    return dp;
}
void all_longest_common_subsequences(string s1, string s2)
{

    vector<vector<int>> dp = longest_sequence_dp(s1, s2);

    int n = s1.length();
    int m = s2.length();

    vector<string> ans1;

    cout << ans(dp, n, m, s1, s2);
}

int main()
{
    string s1 = "abaaa", s2 = "baabaca";
    all_longest_common_subsequences(s1, s2);
    return 0;
}