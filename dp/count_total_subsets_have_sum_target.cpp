#include <bits/stdc++.h>
using namespace std;

int count_total_subsets_having_target_sum(vector<int> v, int target, int index)
{
    if (index == 0)
    {
        if (target == 0 && v[0] == 0) // take+not_take
            return 2;
        if (target == 0 || target == v[0])
            return 1;
        return 0;
    }

    int Not_take = count_total_subsets_having_target_sum(v, target, index - 1);

    int take = 0;
    if (target >= v[index])
    {
        take = count_total_subsets_having_target_sum(v, target - v[index], index - 1);
    }

    return take + Not_take;
}

// using dp
int count_total_subsets_having_target_sum_1(vector<int> v, vector<vector<int>> &dp, int target, int index)
{
    if (index == 0)
    {
        if (target == 0 && v[0] == 0) // take+not_take
            return 2;
        if (target == 0 || target == v[0])
            return 1;
        return 0;
    }

    if (dp[index][target] != -1)
        return dp[index][target];

    int Not_take = count_total_subsets_having_target_sum_1(v, dp, target, index - 1);

    int take = 0;

    if (target >= v[index])
    {

        take = count_total_subsets_having_target_sum_1(v, dp, target - v[index], index - 1);
    }

    return dp[index][target] = take + Not_take;
}

// same changes for other two function to count total subset
// tabulation
int ans2(vector<int> v, int sum)
{

    int n = v.size();

    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for (int i = 0; i <= sum; i++)
    {

        if (i == 0 && v[0] == 0)
            dp[0][i] = 2;
        else if (i == 0)
            dp[0][i] = 1;
        else if (i == v[0])
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            int not_take = dp[i - 1][j];

            int take = 0;

            if (v[i] <= j)
            {
                take = dp[i - 1][j - v[i]];
            }

            dp[i][j] = (take + not_take) % 1000000007;
        }
    }

    return dp[n - 1][sum] % 1000000007;
}

void arr(vector<int> v, vector<vector<int>> &ans, vector<int> &v1, int target, int k)
{

    if (target == 0)
    {
        ans.push_back(v1);
        return;
    }

    // try to take all "unique" number for a perticular position in resultant vector form k to n it help to generate less number of vector, duplicate vector are not form
    for (int i = k; i < v.size(); i++)
    {
        if (v[i] > target)
            return;

        v1.push_back(v[i]);
        arr(v, ans, v1, target - v[i], i + 1);
        v1.pop_back();

        while (i + 1 < v.size() && v[i] == v[i + 1])
            i++;
    }

    return;
}
// return subset having sum==target
vector<vector<int>> combinationSum2(vector<int> &c, int target)
{

    vector<vector<int>> ans;
    vector<int> v;

    sort(c.begin(), c.end());

    arr(c, ans, v, target, 0);

    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 4, 3, 5};
    cout << count_total_subsets_having_target_sum(v, 6, 6);

    return 0;
}