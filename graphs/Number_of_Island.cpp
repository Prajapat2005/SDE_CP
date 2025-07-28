#include <bits/stdc++.h>
using namespace std;

int universal_parent(vector<int> &parent, int n)
{
    if (n == parent[n])
        return n;
    else
        return parent[n] = universal_parent(parent, parent[n]);
}

vector<int> Number_of_Islands(vector<pair<int, int>> adj, int n, int m)
{

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> parent(n * m);
    for (int i = 0; i < n * m; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    vector<int> ans;
    for (int i = 0; i < adj.size(); i++)
    {

        int p = adj[i].first;
        int q = adj[i].second;

        if (visited[p][q] == 0)
        {

            visited[p][q] = 1;
            count++; // if contribute different island
            if (p - 1 >= 0 && visited[p - 1][q] == 1)
            {
                if (universal_parent(parent, p * m + q) != universal_parent(parent, (p - 1) * m + q))
                {
                    parent[p * m + q] = universal_parent(parent, (p - 1) * m + q);
                    count--;
                }
            }
            if (p + 1 < n && visited[p + 1][q] == 1)
            {
                if (universal_parent(parent, p * m + q) != universal_parent(parent, (p + 1) * m + q))
                {
                    if (parent[p * m + q] == p * m + q) // means abhi tk kahi pr bhi connect nhi hua
                        parent[p * m + q] = universal_parent(parent, (p + 1) * m + q);
                    else
                        parent[(p + 1) * m + q] = universal_parent(parent, (p)*m + q);

                    count--;
                }
            }
            if (q - 1 >= 0 && visited[p][q - 1] == 1)
            {
                if (universal_parent(parent, p * m + q) != universal_parent(parent, p * m + q - 1))
                {
                    if (parent[p * m + q] == p * m + q) // means abhi tk kahi pr bhi add nhi hua
                        parent[p * m + q] = universal_parent(parent, p * m + q - 1);
                    else
                        parent[p * m + q - 1] = universal_parent(parent, p * m + q);

                    count--;
                }
            }

            if (q + 1 < m && visited[p][q + 1] == 1)
            {
                if (universal_parent(parent, p * m + q) != universal_parent(parent, p * m + q + 1))
                {
                    if (parent[p * m + q] == p * m + q) // means abhi tk kahi pr bhi add nhi hua
                        parent[p * m + q] = universal_parent(parent, p * m + q + 1);
                    else
                        parent[p * m + q + 1] = universal_parent(parent, p * m + q);

                    count--;
                }
            }
        }
        ans.push_back(count);
    }

    return ans;
}

int main()
{

    int n, m, island;
    cin >> n >> m >> island;
    vector<pair<int, int>> adj;
    for (int i = 0; i < island; i++)
    {

        int n1, n2;
        cin >> n1 >> n2;
        adj.push_back({n1, n2});
    }
    vector<int> ans = Number_of_Islands(adj, n, m);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}