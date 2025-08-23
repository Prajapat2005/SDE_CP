// https://leetcode.com/problems/shortest-path-in-a-weighted-tree/

/*

     1
  2     3
4   5  6   7

   dfs 1 2 4 5 3 6 7

   tree +1 +2 +4 -4 +5 -5 -2 +3 +6 -6 +7 -7 -3 -1

   1 2 3 4 5 6 7

   in-time [0,1,7,2,4,8,10]
   out-time [13,6,12,3,5,9,11]
*/

class SEG
{
public:
    vector<int> seg;
    SEG(int n) { seg.resize(4 * n + 1, 0); }

    void build(int ind, int left, int right, vector<int> &v)
    {
        if (left == right)
        {
            seg[ind] = v[left];
            return;
        }
        int mid = (right - left) / 2 + left;
        build(ind * 2 + 1, left, mid, v);
        build(ind * 2 + 2, mid + 1, right, v);

        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    int query(int ind, int left, int right, int l, int r)
    {

        if (l <= left && right <= r)
        {
            return seg[ind];
        }

        if (l > right || r < left)
        {
            return 0;
        }

        int mid = (right - left) / 2 + left;

        int num1 = query(ind * 2 + 1, left, mid, l, r);
        int num2 = query(ind * 2 + 2, mid + 1, right, l, r);

        return num1 + num2;
    }

    void update(int ind, int left, int right, int i, int val)
    {

        if (left == right)
        {
            seg[ind] = val;
            return;
        }
        int mid = (right - left) / 2 + left;

        if (i <= mid)
        {
            update(ind * 2 + 1, left, mid, i, val);
        }
        else
        {
            update(ind * 2 + 2, mid + 1, right, i, val);
        }

        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }
};

class Solution
{
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> val, in, out, tree, parent;
    int time = 0;

    void dfs(int node, int par)
    {

        parent[node] = par;

        for (auto [child, wt] : adj[node])
        {
            if (child == par)
            {
                continue;
            }
            val[child] = wt;
            dfs(child, node);
        }
    }

    void euler(int node, int par)
    {

        tree.push_back(val[node]);
        in[node] = time;
        time++;

        for (auto [child, v] : adj[node])
        {
            if (child == par)
            {
                continue;
            }
            euler(child, node);
        }

        tree.push_back(-val[node]);
        out[node] = time;
        time++;
    }
    vector<int> treeQueries(int n, vector<vector<int>> &edges,
                            vector<vector<int>> &queries)
    {

        adj.resize(n);
        for (auto it : edges)
        {
            adj[it[0] - 1].push_back({it[1] - 1, it[2]});
            adj[it[1] - 1].push_back({it[0] - 1, it[2]});
        }
        val.resize(n, 0);
        in.resize(n, 0);
        out.resize(n, 0);
        parent.resize(n, 0);

        dfs(0, -1);

        euler(0, -1);

        SEG *seg = new SEG(time);
        seg->build(0, 0, time - 1, tree);

        vector<int> ans;

        for (auto it : queries)
        {
            if (it[0] == 1)
            {

                int u = it[1] - 1, v = it[2] - 1;

                if (parent[v] == u)
                {
                    swap(u, v);
                }

                seg->update(0, 0, time - 1, in[u], it[3]);
                seg->update(0, 0, time - 1, out[u], -it[3]);
            }
            else
            {
                ans.push_back(seg->query(0, 0, time - 1, 0, in[it[1] - 1]));
            }
        }

        return ans;
    }
};