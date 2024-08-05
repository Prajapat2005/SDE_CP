#include <bits/stdc++.h>
using namespace std;

int ans(string s1, string s2, int i, int j)
{
    if (i == -1)
        return j + 1; // j+1 element we have to insert in s1
    if (j == -1)
        return i + 1; // i+1 we have to delete from s1

    if (s1[i] == s2[j])
    { // match
        return ans(s1, s2, i - 1, j - 1);
    }
    else
    {
        int delete_ = ans(s1, s2, i - 1, j) + 1;
        int insert = ans(s1, s2, i, j - 1) + 1;
        int replace = ans(s1, s2, i - 1, j - 1) + 1;

        return min(delete_, min(insert, replace));
    }
}

int ans_2(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == -1)
        return j + 1; // j+1 element we have to insert in s1
    if (j == -1)
        return i + 1; // i+1 we have to delete from s1

    if (s1[i] == s2[j])
    { // match
        if (dp[i][j] == -1)
            dp[i][j] = ans_2(s1, s2, i - 1, j - 1, dp);
        return dp[i][j];
    }
    else
    {
        if (dp[i][j + 1] == -1)
            dp[i][j + 1] = ans_2(s1, s2, i - 1, j, dp);
        int delete_ = dp[i][j + 1] + 1;

        if (dp[i + 1][j] == -1)
            dp[i + 1][j] = ans_2(s1, s2, i, j - 1, dp);
        int insert = dp[i + 1][j] + 1;

        if (dp[i][j] == -1)
            dp[i][j] = ans_2(s1, s2, i - 1, j - 1, dp);
        int replace = dp[i][j] + 1;

        return min(delete_, min(insert, replace));
    }
}

int minDistance(string s1, string s2)
{

    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return ans_2(s1, s2, s1.size() - 1, s2.size() - 1, dp);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
}