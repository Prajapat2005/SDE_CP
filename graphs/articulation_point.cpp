// User function Template for C++

class Solution
{
public:
    vector<int> vis;
    vector<int> in_time;
    vector<int> lowest_time;
    set<int> ans;
    int time = 0;

    void dfs(int node, int par, vector<int> adj[])
    {

        vis[node] = 1;
        in_time[node] = time;
        lowest_time[node] = time;
        int child = 0;
        time++;

        for (auto it : adj[node])
        {

            if (it == par)
            {
                continue;
            }

            if (!vis[it])
            {

                dfs(it, node, adj);

                lowest_time[node] = min(lowest_time[node], lowest_time[it]);

                if (lowest_time[it] >= in_time[node] && par != -1)
                {
                    ans.insert(node);
                }
                child++;
            }
            else
            {
                lowest_time[node] = min(lowest_time[node], in_time[it]);
            }
        }

        if (child > 1 && par == -1)
        {
            ans.insert(node);
        }
    }

    vector<int> articulationPoints(int n, vector<int> adj[])
    {

        vis.resize(n, 0);
        in_time.resize(n, 0);
        lowest_time.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj);
            }
        }

        if (ans.empty())
        {
            return {-1};
        }

        vector<int> arr(ans.begin(), ans.end());

        return arr;
    }
};