#include <bits/stdc++.h>
using namespace std;

int ans(string s)
{

    string s1 = s;
    string s2 = s;
    reverse(s1.begin(), s1.end());

    int n = s1.size();
    int m = s2.size();

    vector<int> pre(m + 1, 0);

    for (int i = 1; i < n + 1; i++)
    {

        vector<int> curr(m + 1, 0);

        for (int j = 1; j < m + 1; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + pre[j - 1];
            }
            else
            {
                curr[j] = max(pre[j], curr[j - 1]);
            }
        }

        pre = curr;
    }

    return pre[m];
}

int min()
{
    string s;
    cin >> s;
    cout << ans(s);
}