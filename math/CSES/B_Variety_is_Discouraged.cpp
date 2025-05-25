#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
#define r(i, a, b) for (int i = a; i < b; i++)
#define rr(i, a, b) for (int i = a; i >= b; i--)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vll vector<long long>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

void solve()
{
    int n;
    cin >> n;
    vi v(n), freq(n + 1, 0);

    r(i, 0, n)
    {
        cin >> v[i];
        freq[v[i]]++;
    }

    int i = 0;
    while (i < n && freq[v[i]] != 1)
    {
        i++;
    }

    if (i == n)
    {
        cout << 0 << "\n";
        return;
    }

    int j = i;
    ii ans;
    int k = INT_MIN;
    while (j < n)
    {

        while (j < n && freq[v[j]] == 1)
        {
            j++;
        }

        if ((j - i) > k)
        {
            k = j - i;
            ans = mp(i + 1, j);
        }

        i = j;

        while (i < n && freq[v[i]] != 1)
        {
            i++;
        }

        j = i;
    }

    cout << ans.ff << " " << ans.ss << "\n";
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}