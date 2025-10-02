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
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

int dp[17][150][2];

// https://codeforces.com/contest/2132/problem/D

int solve(int pos, string s, int sum, bool tight)
{

    if (pos == s.length())
    {
        return sum;
    }

    if (dp[pos][sum][tight] != -1)
    {
        return dp[pos][sum][tight];
    }

    int end = (tight ? (s[pos] - '0') : 9ll);
    int cnt = 0ll;
    for (int i = 0; i <= end; i++)
    {
        cnt += solve(pos + 1, s, sum + i, tight && (i == end));
    }
    return dp[pos][sum][tight] = cnt;
}

void solve()
{
    int k;
    cin >> k;

    vector<int> power(16, 1ll);
    power[0] = 1ll;
    for (int i = 1; i <= 15; i++)
    {
        power[i] = power[i - 1] * 10 * 1ll;
    }

    int ans = 0ll;

    for (int d = 1; d <= 15; d++)
    {
        if (k >= 9 * power[d - 1] * d)
        {
            k -= 9 * power[d - 1] * d;
        }
        else
        {
            int last = (k / d) + power[d - 1] - 1ll;
            int last_next = last + 1ll;
            int remain = k % d;
            string s = to_string(last_next);
            for (int i = 0; i < remain; i++)
            {
                ans += (s[i] - '0') * 1ll;
            }
            memset(dp, -1, sizeof(dp));
            ans += solve(0, to_string(last), 0ll, true);
            break;
        }
    }

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