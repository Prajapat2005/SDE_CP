#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string s)
{

    int n = s.length();

    vector<int> lps(n, 0);
    int pref = 0, suf = 1;
    while (suf < n)
    {
        if (s[pref] == s[suf])
        {
            lps[suf] = pref + 1;
            pref++;
            suf++;
        }
        else
        {
            if (pref == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pref = lps[pref - 1];
            }
        }
    }

    return lps;
}

int main()
{
    string s;
    cin >> s;

    cout << LPS(s)[s.length() - 1];
}