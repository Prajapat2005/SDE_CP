// https://leetcode.com/contest/weekly-contest-436/problems/count-substrings-divisible-by-last-digit/description/?slug=count-substrings-divisible-by-last-digit&region=global_v2

class Solution
{
public:
    long long countSubstrings(string s)
    {

        long long n = s.length();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(10, vector<long long>(10, 0)));

        long long ans = 0;

        for (long long i = 0; i < n; i++)
        {

            long long digit = s[i] - '0';
            for (long long divisor = 1; divisor <= 9; divisor++)
            {
                for (long long rem = 0; rem <= 9; rem++)
                {

                    long long new_rem = (rem * 10 + digit) % divisor;
                    dp[i][divisor][new_rem] +=
                        i - 1 >= 0 ? dp[i - 1][divisor][rem] : 0;
                }
                dp[i][divisor][digit % divisor]++;
            }
            ans += dp[i][digit][0];
        }

        return ans;
    }
};
