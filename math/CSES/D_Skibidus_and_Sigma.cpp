#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vi> v(n, vi(m));
    vii arr(n);

    r(i, 0, n)
    {
        int x = 0;
        int y = 0;
        int p = m;
        r(j, 0, m)
        {
            cin >> v[i][j];
            x += v[i][j];
            y += p * v[i][j];
            p--;
        }
        sort(all(v[i]));
        arr[i] = mp(x, y);
    }

    sort(all(arr));

    int ans = 0;
    r(i, 0, n)
    {
        ans += (arr[i].ss + arr[i].ff * i * m);
    }

    cout << ans << "\n";
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