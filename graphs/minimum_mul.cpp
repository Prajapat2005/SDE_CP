#include <bits/stdc++.h>
using namespace std;

int dijkstra(int src, int des, vector<int> v)
{

    vector<int> dis(100000, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, src});
    dis[src] = 0;

    while (!q.empty())
    {

        int step = q.top().first;
        int num = q.top().second;

        q.pop();

        if (num == des)
            return step;

        for (int i = 0; i < v.size(); i++)
        {
            int mul = (num * v[i]) % 100000;

            if (dis[mul] > step + 1)
            {
                dis[mul] = step + 1;
                q.push({step + 1, mul});
            }
        }
    }

    return -1;
}
int main()
{
    cout << dijkstra(3, 30, {2, 5, 7});
}