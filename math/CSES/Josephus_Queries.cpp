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

int solve(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }

    if (k <= ((n + 1) >> 1))
    {
        if (n & 1)
        {
            return (2 * k) % n;
        }
        else
        {
            return 2 * k;
        }
    }

    if (n & 1)
    {
        return (solve(n / 2, k - ((n + 1) >> 1)) << 1) + 1;
    }
    else
    {
        return (solve(n / 2, k - ((n + 1) >> 1)) << 1) - 1;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << "\n";
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