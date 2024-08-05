#include <bits/stdc++.h>
using namespace std;

/* same concept ans frog jump */
int max_sum(vector<vector<int>> v, int index, int k)
{ // k is that task which is lastely perform
    if (index == 0)
    {
        if (k == 0)
            return max(v[index][1], v[index][2]);
        // if k==0 it mean at that movement we can not preform 0th task
        else if (k == 1)
            return max(v[index][2], v[index][0]);
        // if k==1 it mean at that movement we can not preform 1st task
        else
            return max(v[index][1], v[index][0]);
        // if k==2 it mean at that movement we can not preform 2nd task
    }
    int p1 = 0, p2 = 0, p3 = 0;
    if (k != 0)
        p1 = v[index][0] + max_sum(v, index - 1, 0); // if k!=0 means we can perform 0th task now
    if (k != 1)
        p2 = v[index][1] + max_sum(v, index - 1, 1); // if k!=1 means we can perform 1st task now
    if (k != 2)
        p3 = v[index][2] + max_sum(v, index - 1, 2); // if k!=2 means we can perform 2nd task now

    return max(p1, max(p2, p3));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Create a 2D DP (Dynamic Programming) table to store the maximum points
    // dp[i][j] represents the maximum points at day i, considering the last activity as j
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Initialize the DP table for the first day (day 0)
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Iterate through the days starting from day 1
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            // Iterate through the tasks for the current day
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    // Calculate the points for the current activity and add it to the
                    // maximum points obtained on the previous day (recursively calculated)
                    int activity = points[day][task] + dp[day - 1][task];
                    // Update the maximum points for the current day and last activity
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    // The maximum points for the last day with any activity can be found in dp[n-1][3]
    return dp[n - 1][3];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> v[i][j];
    }
    cout << max_sum(v, n - 1, -1);
    // max(when we start from 0th task, when we start from 1st task , when we start from 2nd task)
    return 0;
}