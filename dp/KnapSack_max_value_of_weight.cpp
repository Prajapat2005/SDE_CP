#include <bits/stdc++.h>
using namespace std;

int max_value(vector<vector<int>> v, int wt, int index)
{

  if (wt == 0)
    return 0; // capacity of bag become zero
  if (index == 0)
  {
    // at index zero if weight is less than or equal to capacity then we will take it other wise not
    if (v[0][0] <= wt)
      return v[1][0];
    else
      return 0;
  }

  int Not_take = max_value(v, wt, index - 1);
  int take = 0;
  if (v[0][index] <= wt)
  {
    take = v[1][index] + max_value(v, wt - v[0][index], index - 1);
  }

  return max(take, Not_take);
}

// there is some overlaping subproblem so we can rectify using dp as done as before dp[n][wt+1]

int max_value(vector<vector<int>> v, int wt, int index, vector<vector<int>> &dp)
{

  if (wt == 0)
    return 0; // capacity of bag become zero
  if (index == 0)
  {
    // at index zero if weight is less than or equal to capacity then we will take it other wise not
    if (v[0][0] <= wt)
      return v[1][0];
    else
      return 0;
  }

  if (dp[index][wt] != -1)
    return dp[index][wt];

  int Not_take = max_value(v, wt, index - 1);
  int take = 0;
  if (v[0][index] <= wt)
  {
    take = v[1][index] + max_value(v, wt - v[0][index], index - 1);
  }

  return dp[index][wt] = max(take, Not_take);
}

// tabulation
int max_value_1(vector<vector<int>> v, vector<vector<int>> dp, int wt, int index)
{

  for (int i = 0; i <= index; i++)
    dp[i][0] = 0;
  for (int i = 0; i <= wt; i++)
  {
    if (v[0][0] <= i)
      dp[0][i] = v[1][0];
    else
      dp[0][i] = 0;
  }

  for (int i = 1; i <= index; i++)
  {
    for (int j = 1; j <= wt; j++)
    {
      int Not_take = dp[i - 1][j]; // if we not take then wt remain same and index decrease
      int take = 0;
      if (v[0][i] <= j)
      {
        take = v[1][i] + dp[i - 1][j - v[0][i]]; // if we take then wt reduce to wt-(current index wt) and index decrease
      }
      dp[i][j] = max(take, Not_take);
    }
  }
  return dp[index][wt];
}

// without using extra space
int max_value_2(vector<vector<int>> v, int wt, int index)
{

  vector<int> prev(wt + 1, 0); // index==0 base case
  for (int i = 0; i <= wt; i++)
  {
    if (v[0][0] <= i)
      prev[i] = v[1][0];
  }

  vector<int> curr(wt + 1, 0);
  curr[0] = 0;
  prev[0] = 0; // wt==0 base case

  for (int i = 1; i <= index; i++)
  {
    for (int j = 1; j <= wt; j++)
    {
      int Not_take = prev[j];
      int take = 0;
      if (v[0][i] <= j)
      {
        take = v[1][i] + prev[j - v[0][i]];
      }
      curr[j] = max(take, Not_take);
    }
    prev = curr;
  }
  return prev[wt];
}

// if there is infinite supply
// some condition will change when we 'take' we write index instead of index-1 because of infinite supply
// 0th index base case will change , beacue multiple time you can take 0th index
int max_value_infinite_supply(vector<vector<int>> v, int wt, int index)
{

  if (wt == 0)
    return 0; // capacity of bag become zero
  if (index == 0)
  {
    // at index zero if weight is less than or equal to capacity then we will take it other wise not
    if (v[0][0] <= wt)
      return (wt / v[0][0]) * v[1][0];
    else
      return 0;
  }

  int Not_take = max_value(v, wt, index - 1);
  int take = 0;
  if (v[0][index] <= wt)
  {
    take = v[1][index] + max_value(v, wt - v[0][index], index);
  }

  return max(take, Not_take);
}

// same other 2 function can be also write by changing two condition

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> v(2, vector<int>(n));
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> v[i][j];
  }
  cout << max_value(v, 6, 2);

  return 0;
}