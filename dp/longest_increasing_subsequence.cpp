#include <bits/stdc++.h>
using namespace std;

int max_increase_subsequence(vector<int> v, int i, int p_i)
{

    if (i == v.size())
        return 0;

    if (p_i == -1 || v[p_i] <= v[i])
    {
        int take = 1 + max_increase_subsequence(v, i + 1, i);
        int not_take = max_increase_subsequence(v, i + 1, p_i);
        return max(take, not_take);
    }
    else
        return max_increase_subsequence(v, i + 1, p_i);
}

// using dp of size n+1 X n+1  0 to n and -1 to n-1
int max_increase_subsequence_dp(vector<int> v, vector<vector<int>> &dp, int i, int p_i)
{

    if (i == v.size())
        return 0;

    if (dp[i][p_i + 1] != -1)
        return dp[i][p_i + 1];

    if (p_i == -1 || v[p_i] < v[i])
    {

        return dp[i][p_i + 1] = max(1 + max_increase_subsequence_dp(v, dp, i + 1, i), max_increase_subsequence_dp(v, dp, i + 1, p_i));
    }
    else
    {
        return dp[i][p_i + 1] = max_increase_subsequence_dp(v, dp, i + 1, p_i);
    }
}

// tabulation
// dp[n+1][n+1]  index 0 to n and prev_element -1 to n-1
int max_increase_subsequence_tabulation(vector<int> v)
{

    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // for index==n dp[index][i]=0 base case
    for (int index = n - 1; index >= 0; index--)
    {
        for (int prev_index = index - 1; prev_index >= -1; prev_index--)
        {
            if (v[prev_index] <= v[index] || prev_index == -1)
            {
                dp[index][prev_index + 1] = max(1 + dp[index + 1][index + 1], dp[index + 1][prev_index + 1]);
            }
            else
                dp[index][prev_index + 1] = dp[index + 1][prev_index + 1];
        }
    }

    return dp[0][-1 + 1];
}

void ans2(int v[], int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int pre_i = n; pre_i >= 0; pre_i--)
        {

            if (pre_i == 0 || v[pre_i - 1] < v[i]) // 0->-1 n->n-1 means pre=index+1 for pre=index
            {
                dp[i][pre_i] = max(1 + dp[i + 1][i + 1], dp[i + 1][pre_i]); // when we take pre=index+1
            }
            else
            {
                dp[i][pre_i] = dp[i + 1][pre_i];
            }
        }
    }

    cout << dp[0][0] << "\n";
}

// you can do space obtimisation because index+1 is present

vector<int> print_longest(vector<int> v, int n)
{

    vector<int> dp(n, 1);
    int maxi = INT_MIN;
    // dp[i] is max length of increase substring end at index i
    for (int i = 0; i < n; i++)
    {
        for (int pre = 0; pre <= i - 1; pre++)
        {

            if (v[i] > v[pre])
            {
                dp[i] = max(dp[pre] + 1, dp[i]);
            }

            maxi = max(dp[i], maxi);
        }
    }

    vector<int> ans(1);
    ans[0] = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {

        if (dp[i] == maxi && v[i] < ans[ans.size() - 1])
        {
            ans.push_back(v[i]);
            maxi--;
        }

        if (maxi == 0)
            break;
    }
    ans.erase(ans.begin());
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp_1(n, vector<int>(n + 1, -1));
    cout << max_increase_subsequence_dp(v, dp_1, 0, -1) << endl;
    cout << max_increase_subsequence_tabulation(v) << endl;
    return 0;
}