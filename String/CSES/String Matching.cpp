#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string &s)
{
    int n = s.length();

    int pref = 0, suf = 1;
    vector<int> lps(n, 0);

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

int string_Matching(string &s1, string &s2)
{

    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> lps = LPS(s2);

    int i = 0;
    int j = 0;

    int count = 0;

    while (i < n1)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }

        if (j == n2)
        {
            count++;
            j = lps[j - 1];
        }
    }

    return count;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << string_Matching(s1, s2);
}