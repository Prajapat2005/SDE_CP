/*https://codeforces.com/contest/1955/problem/E*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        for (int k = n; k > 0; k--)
        {
            vector<int> v(n), end(n + 1, 0);

            for (int i = 0; i < n; i++)
            {
                v[i] = s[i] - '0';
            }

            int inv = 0;
            for (int i = 0; i < n; i++)
            {
                int curr_inv = inv - end[i];

                if (curr_inv & 1)
                {
                    v[i] = v[i] ^ 1;
                }

                if (v[i] == 0)
                {
                    if (i + k <= n)
                    {
                        inv++;
                        v[i] = 1;
                    }
                    else
                    {
                        break;
                    }
                }

                if (i + k <= n)
                {
                    end[i + k] = inv;
                }
            }

            if (*min_element(v.begin(), v.end()) == 1)
            {
                cout << k << endl;
                break;
            }
        }
    }
}