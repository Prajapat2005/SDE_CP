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

// https://codeforces.com/contest/2013/my

bool check1(vi v, int mid)
{
    int n = v.size();
    int cnt = 0;
    r(i, 0, n)
    {
        if (v[i] >= mid)
        {
            cnt += v[i] - mid;
        }
        else
        {
            cnt = max(0LL, cnt - (mid - v[i]));
        }
    }

    return cnt == 0;
}

bool check2(vi v, int mid)
{
    int n = v.size();
    int cnt = 0;
    rr(i, n - 1, 0)
    {
        if (v[i] <= mid)
        {
            cnt += mid - v[i];
        }
        else
        {
            cnt = max(0LL, cnt - (v[i] - mid));
        }
    }

    return cnt == 0;
}

void solve()
{
    int n;
    cin >> n;
    vi v(n);
    r(i, 0, n)
    {
        cin >> v[i];
    }

    int l = *min_element(all(v));
    int r = *max_element(all(v));

    int maxi = r;
    int mini = l;

    while (l <= r)
    {
        int mid = ((r - l) >> 1) + l;
        if (check1(v, mid))
        {
            maxi = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    l = mini;
    r = maxi;

    while (l <= r)
    {
        int mid = ((r - l) >> 1) + l;
        if (check2(v, mid))
        {
            mini = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << maxi - mini << "\n";
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