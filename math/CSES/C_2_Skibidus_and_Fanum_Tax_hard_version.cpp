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

void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);

    r(i, 0, n)
    {
        cin >> a[i];
    }

    r(i, 0, m)
    {
        cin >> b[i];
    }

    sort(all(b));

    rr(i, m - 1, 0)
    {
        if (b[i] - a[n - 1] > a[n - 1])
        {
            a[n - 1] = b[i] - a[n - 1];
        }
        else
        {
            break;
        }
    }

    rr(i, n - 2, 0)
    {
        if (a[i] <= a[i + 1])
        {
            continue;
        }

        int it = lower_bound(all(b), 2 * a[i]) - b.begin();

        if (it == 0)
        {
            no;
            return;
        }
        else
        {
            a[i] = b[it - 1] - a[i];
            if (a[i] > a[i + 1])
            {
                no;
                return;
            }
        }
    }

    yes;
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