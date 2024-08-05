#include <bits/stdc++.h>
using namespace std;

void ans(vector<vector<int>> adj, map<int, int> &a, string &s, vector<char> &c, int z)
{

    if (adj[z].size() == 1)
        ans(adj, a, s, c, adj[z][0]);
    else if (adj[z].size() == 2)
    {
        if (adj[z][0] > adj[z][1])
        {
            ans(adj, a, s, c, adj[z][1]);
            ans(adj, a, s, c, adj[z][0]);
        }
        else
        {
            ans(adj, a, s, c, adj[z][0]);
            ans(adj, a, s, c, adj[z][1]);
        }
    }
    a[z] = s.length();
    s = s + c[z - 1];
}

bool palindrome(string s)
{

    int i = 0, j = s.length() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int main()
{
    vector<vector<int>> adj = {{}, {2, 3}, {4, 5}, {}, {}, {}};
    map<int, int> a;
    vector<char> c = {'a', 'b', 'a', 'b', 'c'};
    string s = "";
    ans(adj, a, s, c, 1);
    vector<int> q = {1, 2};
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << it->first << " " << it->second;
        cout << "\n";
    }
    for (int i = 0; i < q.size(); i++)
    {
        if (palindrome(s.substr(0, a[i] + 1)) == true)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    cout << s;
}
