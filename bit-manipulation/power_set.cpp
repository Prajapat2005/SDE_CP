#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> power_set(vector<int> v)
{

    int total_no_of_set = 1 << (v.size()); // 2^n

    vector<vector<int>> ans;
    for (int i = 0; i < total_no_of_set; i++)
    {
        vector<int> temp;
        for (int j = 0; j < v.size(); j++)
        {
            if (i & (1 << j))
                temp.push_back(v[j]);
        }
        ans.push_back(temp);
    }

    return ans;
}
int main()
{
    vector<int> v = {1, 2, 3};
    vector<vector<int>> ans = power_set(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
