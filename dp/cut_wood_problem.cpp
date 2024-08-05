#include <bits/stdc++.h>
using namespace std;

// like knapsack
int ans(int w[], int wt, int i, vector<vector<int>> &dp)
{

    if (wt == 0)
        return 0;

    if (i == 0)
    {
        if (wt >= 1)
            return wt * w[i];
    }

    if (dp[i][wt] != -1)
        return dp[i][wt];

    int not_take = ans(w, wt, i - 1, dp);
    int take = 0;

    if (wt >= i + 1)
    {
        take = w[i] + ans(w, wt - i - 1, i, dp);
    }

    return dp[i][wt] = max(take, not_take);
}

int main()
{
}