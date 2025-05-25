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

int SQRT(int n)
{

    int l = 1;
    int r = n;
    while (l <= r)
    {
        int mid = ((r - l) >> 1) + l;
        if (mid * mid <= n)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return r;
}

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    int x = SQRT(n);
    for (int i = 1; i <= x; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
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