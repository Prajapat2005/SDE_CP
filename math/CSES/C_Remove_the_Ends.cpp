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
    vi v(n);
    r(i, 0, n)
    {
        cin >> v[i];
    }

    int i = 0;
    int ans = 0;
    while (i < n && v[i] > 0)
    {
        ans += v[i];
        i++;
    }

    int j = n - 1;
    while (j >= 0 && v[j] < 0)
    {
        ans += -v[j];
        j--;
    }

    if (i > j)
    {
        cout << ans << "\n";
        return;
    }

    vi neg, pos;
    while (i < j)
    {
        int sum = 0;
        while (i < n && v[i] < 0)
        {
            sum += -v[i];
            i++;
        }

        neg.pb(sum);

        sum = 0;

        while (i < n && v[i] > 0)
        {
            sum += v[i];
            i++;
        }

        pos.pb(sum);
    }

    int sum = ans;

    int m = pos.size();

    for (int i = m - 2; i >= 0; i--)
    {
        neg[i] += neg[i + 1];
    }

    for (int i = 1; i < m; i++)
    {
        pos[i] += pos[i - 1];
    }

    for (int i = 0; i < m - 1; i++)
    {
        ans = max(sum + pos[i] + neg[i + 1], ans);
    }

    ans = max({ans, sum + neg[0], sum + pos[m - 1]});

    cout << ans << "\n";
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