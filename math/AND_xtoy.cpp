#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ii pair<int, int>
#define int long long
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

// x to y AND
int solve(int x, int y)
{

    r(i, 0, 64)
    {
        if (y <= x)
        {
            return y;
        }

        if ((1LL << i) & y)
        {
            y &= ~(1LL << i);
        }
    }

    return y;
}

// minimum y so that AND n to y be x
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        int l = n;
        int r = (1LL << 61);

        int ans = LLONG_MAX;

        while (l <= r)
        {
            int mid = ((r - l) >> 1) + l;

            int num = solve(n, mid);

            if (num <= x)
            {
                r = mid - 1LL;
            }
            else
            {
                l = mid + 1LL;
            }

            if (num == x)
            {
                ans = min(ans, mid);
            }
        }

        cout << ((ans == LLONG_MAX) ? (-1) : (ans)) << "\n";
    }
}