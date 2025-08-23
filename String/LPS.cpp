#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string s)
{

    int n = s.length();

    vector<int> lps(n, 0);
    int curr_lps_len = 0, i = 1;

    while (i < n)
    {
        if (s[curr_lps_len] == s[i])
        {
            curr_lps_len++;
            lps[i] = curr_lps_len;
            i++;
        }
        else
        {
            if (curr_lps_len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                curr_lps_len = lps[curr_lps_len - 1];
            }
        }
    }

    return lps;
}

vector<int> LPS(string s)
{

    int n = s.length();
    vector<int> lps(n);
    lps[0] = 0;
    int curr_lps_len = 0;

    for (int i = 1; i < n; i++)
    {
        while (curr_lps_len > 0 && s[curr_lps_len] != s[i])
        {
            curr_lps_len = lps[curr_lps_len - 1];
        }

        if (s[curr_lps_len] == s[i])
        {
            curr_lps_len++;
        }

        lps[i] = curr_lps_len;
    }

    return lps;
}

int main()
{
    string s;
    cin >> s;

    for (auto it : LPS(s))
    {
        cout << it << " ";
    }
}