#include <bits/stdc++.h>
using namespace std;
int max_profit(vector<int> v)
{

    int profit = INT_MIN;
    int min_buy_price = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        profit = max(profit, v[i] - min_buy_price);
        if (v[i] < min_buy_price)
            min_buy_price = v[i];
    }
    return profit;
}

// multiple buy or sell
// we move 0 index to n-1 index we can do n-1 to 0 only change in base case and moving pointer
// there is overlaping of subproblem we can obtimized it by using dp array[size][2] 2 is for true or false
int max_profit_2(vector<int> v, int index, bool flag)
{

    if (index == v.size() - 1)
    { // at last point we can only sell ont buy
        if (flag = false)
            return v[index];
        else
            return 0;
    }

    if (flag == true)
    {
        int if_buy = max_profit_2(v, index + 1, false) - v[index]; // if we buy profit-buying amount then at another point we have to sell for that flag = false
        int not_buy = max_profit_2(v, index + 1, true);            // if we not buy then at another point we have to buy for that flag = true
        return max(if_buy, not_buy);
    }
    else
    {
        int if_sell = max_profit_2(v, index + 1, true) + v[index]; // if we sell profit+sell amount then at another point we have to buy for that flag = true
        int not_sell = max_profit_2(v, index + 1, false);          // if we not sell then at another point we have to sell for that flag = false
        return max(if_sell, not_sell);
    }
}

// tabulation
// true means buy
int max_profit_tabulation(vector<int> v, vector<vector<int>> dp)
{

    int n = v.size();
    dp[n - 1][1] = 0;        // at last point buy
    dp[n - 1][0] = v[n - 1]; // at last point sell

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j >= 0; j--)
        {

            if (j == 0)
            {

                dp[i][j] = max(dp[i + 1][1] + v[i], dp[i + 1][0]);
            }
            else
            {

                dp[i][j] = max(dp[i + 1][0] - v[i], dp[i + 1][1]);
            }
        }
    }
    return dp[0][1];
}

// there is slace obtimization because only i+1 is present
int max_profit_tabulation_2(vector<int> v)
{

    int n = v.size();
    vector<int> curr(2, 0);
    vector<int> fut(2, 0);
    fut[0] = v[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j >= 0; j--)
        {

            if (j == 0)
            {

                curr[j] = max(fut[1] + v[i], fut[0]);
            }
            else
            {

                curr[j] = max(fut[0] - v[i], fut[1]);
            }
        }
        fut = curr;
    }
    return fut[1];
}

int max_profit_2(vector<int> v, vector<vector<int>> dp)
{
    int n = v.size();
    dp[n - 1][1] = 0;
    dp[n - 1][0] = v[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j >= 0; j--)
        {

            if (j == 0)
            {

                dp[i][j] = max(dp[i + 1][1] + v[i], dp[i + 1][0]);
            }
            else
            {

                dp[i][j] = max(dp[i + 1][0] - v[i], dp[i + 1][1]);
            }
        }
    }
    return dp[0][1];
}

// you can buy and sell stock atmost x   times count = x
int ans(vector<int> v, int flag, int i, int count, vector<vector<vector<int>>> &dp)
{

    if (count == 0)
        return 0;

    if (i == v.size() - 1)
    {
        if (flag == true)
            return 0;
        else
            return v[i];
    }

    if (dp[flag][count][i] != -1)
        return dp[flag][count][i];

    if (flag == true)
    { // buy
        return dp[flag][count][i] = max(ans(v, false, i + 1, count, dp) - v[i], ans(v, true, i + 1, count, dp));
    }
    else
    {
        return dp[flag][count][i] = max(ans(v, true, i + 1, count - 1, dp) + v[i], ans(v, false, i + 1, count, dp));
    }
}

int ans2(vector<int> &v, int x)
{

    int n = v.size();
    vector<vector<int>> fut(2, vector<int>(x + 1, 0)); // count==0 already=0

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < x + 1; j++)
        {
            if (i == 0)
            {
                fut[i][j] = v[n - 1];
            }
            else
                fut[i][j] = 0;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(2, vector<int>(x + 1, 0));

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < x + 1; k++)
            {

                if (k == 0)
                {
                    curr[j][k] = 0;
                    continue;
                }

                if (j == 0)
                {
                    curr[j][k] = max(v[i] + fut[1][k - 1], fut[0][k]);
                }
                else
                {
                    curr[j][k] = max(fut[0][k] - v[i], fut[1][k]);
                }
            }
        }

        fut = curr;
    }

    return fut[1][x];
}

int main()
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << max_profit(v);

    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << max_profit_2(v, 0, true);
    return 0;
}