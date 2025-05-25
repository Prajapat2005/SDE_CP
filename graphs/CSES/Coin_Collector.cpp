#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> vis(100005);
stack<int> st;
vector<int> adj1[100005];
vector<int> adj2[100005];
set<int> adj[100005];
vector<int> comp(100005);
vector<int> coins(100005);
int k = 1;

void dfs1(int node)
{

    vis[node] = 1;

    for (auto &it : adj1[node])
    {
        if (!vis[it])
        {
            dfs1(it);
        }
    }

    st.push(node);
}

int dfs2(int node)
{

    comp[node] = k;

    int count = 0;

    for (auto &it : adj2[node])
    {
        if (!comp[it])
        {
            count += dfs2(it);
        }
        else if (comp[it] != k)
        {
            adj[comp[it] - 1].insert(k - 1);
        }
    }

    return count + coins[node];
}

int maxi(int node, vector<int> &sum, vector<int> &dp)
{

    int count = 0;
    vis[node] = 1;

    if (dp[node] != -1)
    {
        return dp[node];
    }

    for (auto &it : adj[node])
    {
        count = max(count, maxi(it, sum, dp));
    }

    return dp[node] = count + sum[node];
}

int32_t main()
{
    fastio;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }

    vector<int> sum;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (comp[node])
            continue;

        sum.push_back(dfs2(node));
        k++;
    }

    fill(vis.begin(), vis.end(), 0);

    int count = 0;

    vector<int> dp(k - 1, -1);

    for (int i = 0; i < k - 1; i++)
    {
        if (!vis[i])
        {
            count = max(count, maxi(i, sum, dp));
        }
    }

    cout << count;
}
