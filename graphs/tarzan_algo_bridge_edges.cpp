// https://leetcode.com/problems/critical-connections-in-a-network/

class Solution
{
private:
    vector<int> in_time;
    vector<int> lowest_time;
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    vector<int> vis;
    int time = 0;

public:
    void dfs(int node, int par)
    {

        in_time[node] = time;
        lowest_time[node] = time;
        vis[node] = 1;
        time++;

        int cnt = 0;

        for (auto it : adj[node])
        {

            if (it == par)
            {
                continue;
            }

            if (vis[it] == 0)
            {

                dfs(it, node);
                lowest_time[node] = min(lowest_time[node], lowest_time[it]);

                if (lowest_time[it] > in_time[node])
                {
                    ans.push_back({it, node});
                }
                else
                {
                    // not bridge
                }
            }
            else
            {
                lowest_time[node] = min(lowest_time[node], lowest_time[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>> &connections)
    {

        in_time.resize(n, 0);
        lowest_time.resize(n, 0);
        adj.resize(n);
        vis.resize(n, 0);

        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0, 0);

        return ans;
    }
};