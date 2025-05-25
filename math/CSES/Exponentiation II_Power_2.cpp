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

int power(int n, int m, int MOD)
{
    int ans = 1;

    if (m == 0)
    {
        return 1;
    }

    if (n == 0)
    {
        return 0;
    }
    while (m)
    {
        if (m & 1)
        {
            ans = ((ans % MOD) * (n % MOD)) % MOD;
            m--;
        }
        else
        {
            n = ((n % MOD) * (n % MOD)) % MOD;
            m = m / 2;
        }
    }

    return ans;
}

void solve()
{

    int MOD = 1e9 + 7;
    int a, b, c;
    cin >> a >> b >> c;
    cout << power(a, power(b, c, MOD - 1), MOD) << '\n';
    return;
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