#include <bits/stdc++.h>
using namespace std;

vector<int> Z_algo(string &s)
{

    int n = s.length();
    vector<int> z(n, 0);

    int l = 0, r = 0;

    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = z[i - l];
            if (i + z[i] > r)
            {
                z[i] = r - i;
            }
        }

        while ((i + z[i] < n) && (s[z[i]] == s[i + z[i]]))
        {
            z[i]++;
        }

        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

int main()
{
    string s;
    cin >> s;

    vector<int> z = Z_algo(s);

    for (int i = s.length() - 1; i > 0; i--)
    {
        //  cout << z[i] << " ";
        if (z[i] == (s.length() - i))
        {
            cout << z[i] << " ";
        }
    }
}