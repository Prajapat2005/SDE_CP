#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<int> suf_min(n);
        suf_min[n - 1] = v[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            suf_min[i] = min(v[i], suf_min[i + 1]);
        }

        int MINI = INT_MAX;

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int mini = suf_min[i];

            while (i < n && mini != v[i])
            {
                MINI = min(MINI, v[i]);
                ans.push_back(v[i] + 1);
                i++;
            }

            if (i < n && MINI + 1 >= v[i])
                ans.push_back(v[i]);
            else
            {
                ans.push_back(v[i] + 1);
            }
        }

        sort(ans.begin(), ans.end());

        for (auto &it : ans)
        {
            cout << it << " ";
        }

        cout << "\n";
    }
}