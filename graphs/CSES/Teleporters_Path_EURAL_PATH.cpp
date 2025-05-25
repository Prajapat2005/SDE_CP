#include <bits/stdc++.h>
using namespace std;

// Eulerian circuit for directed graph
// https://youtu.be/3BJTw_OWvTU?si=GOjyOljC7WadhyZs
// A Eulerian circuit is a path in a graph that passes through all of its edges exactly once. A Eulerian cycle is a Eulerian path that is a cycle.

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> adj[n];
    vector<int> in(n, 0);
    vector<int> out(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        out[u]++;
        in[v]++;
        adj[u].insert(v);
    }

    if (((out[0] - in[0]) != 1) || ((in[n - 1] - out[n - 1]) != 1))
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if ((in[i] != out[i]))
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<int> ans;
    stack<int> st;
    st.push(0);

    while (!st.empty())
    {
        int node = st.top();

        if (adj[node].empty())
        {
            ans.push_back(node);
            st.pop();
        }
        else
        {
            int i = *(adj[node].begin());
            adj[node].erase(i);
            st.push(i);
        }
    }

    if (ans.size() != (m + 1))
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    reverse(ans.begin(), ans.end());

    for (auto &it : ans)
    {
        cout << it + 1 << " ";
    }
}