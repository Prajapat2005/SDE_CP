#include <bits/stdc++.h>
using namespace std;

/*
Given a position, this function gives the length of the longest string that's both the prefix of S and of the suffix of S starting at the given position.

aabxaabxcaabxaabxay   Z=[18,1,0,0,4,1,0,0,0,8,1,0,0,5,1,0,0,1,0]

Let's also take a closer look at Z_9=8 (0-indexed) for the second string.
The value for this position is 8 because that's the longest common prefix between the string itself  aabxaabxcaabx   aabxay and the suffix starting  at position 9  aabxaabxay (also 0-indexed).
*/

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
}