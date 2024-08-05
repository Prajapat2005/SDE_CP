#include <bits/stdc++.h>
using namespace std;

bool target_sum(vector<int> v, int target, int index)
{
    if (target == 0)
        return true; // atrget achieve

    if (index == 0)
    { // reach last index of array
        if (target == v[0])
            return true;
        else
            return false;
    }

    bool Not_take = target_sum(v, target, index - 1);
    // if we not take current element then target remain same

    // if we take element must be less than or equal to that element and target reduce to target-v[index]
    bool take;
    if (target >= v[index])
    {
        take = target_sum(v, target - v[index], index - 1);
    }
    else
        take = false;

    return take || Not_take; // if any of condition true ans will be true
}

// using DP
bool target_sum_1(vector<int> v, vector<vector<int>> dp, int target, int index)
{

    if (target == 0)
        return true;

    if (index == 0)
    {
        if (target == v[0])
            return true;
        else
            return false;
    }

    if (dp[index][target] != -1)
        return dp[index][target];

    bool Not_take = target_sum_1(v, dp, target, index - 1);

    bool take = false;

    if (target >= v[index])
    {
        take = target_sum_1(v, dp, target - v[index], index - 1);
    }

    return dp[index][target] = take || Not_take;
}

// creat ans array from base case to ans
bool target_sum_2(vector<int> v, vector<vector<int>> dp, int target, int index)
{
    for (int i = 0; i <= index; i++)
        dp[i][0] = true;

    for (int i = 0; i <= target; i++)
    {
        if (i == v[0])
            dp[0][i] = true;
        else
            dp[0][i] = false;
    }

    for (int i = 1; i <= index; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool Not_take = dp[i - 1][j];
            bool take = false;
            if (v[i] <= j)
            {
                take = dp[i - 1][j - v[i]];
            }
            dp[i][j] = take || Not_take;
        }
    }
    return dp[index][target];
}

// witout using extra space
bool target_sum_2(vector<int> v, int target, int index)
{
    vector<int> prev(target + 1, 0), curr(target, 0); // array of different target create

    prev[0] = true;
    curr[0] = true; // first base case target==0 return true;
    if (v[0] <= target)
        prev[v[0]] = true; // 2nd base case target==v[0] true;

    for (int i = 1; i <= index; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool Not_take = prev[j];
            bool take = false;
            if (v[i] <= j)
                take = prev[j - v[i]];
            curr[j] = take || Not_take;
        }
        prev = curr;
    }
    return prev[target];
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    cout << target_sum(v, 5, 3);

    vector<vector<int>> dp(4, vector<int>(6, -1));
    cout << target_sum_1(v, dp, 5, 3);
    return 0;
}