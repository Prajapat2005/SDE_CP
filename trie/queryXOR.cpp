#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2];

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    bool containKey(int bit)
    {
        return links[bit] != NULL;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int k = (num >> i) & 1;
            if (!node->containKey(k))
            {
                node->put(k, new Node());
            }
            node = node->get(k);
        }
    }
    int maxXOR(int num)
    {
        Node *node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int k = (num & (1 << i));
            if (k)
            {
                k = 0;
            }
            else
            {
                k = 1;
            }
            if (node->containKey(k))
            {
                ans = ans + (1 << i);
                node = node->get(k);
            }
            else
            {
                if (k == 1)
                    node = node->get(0);
                else
                    node = node->get(1);
            }
        }

        return ans;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &q)
{
    Trie *trie = new Trie();
    vector<int> ans(q.size());
    vector<pair<int, pair<int, int>>> v;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < q.size(); i++)
    {
        v.push_back({q[i][1], {q[i][0], i}});
    }
    sort(v.begin(), v.end());
    int j = 0;
    for (int i = 0; i < q.size(); i++)
    {
        int xi = v[i].second.first;
        int ai = v[i].first;
        int ind = v[i].second.second;
        while (j < arr.size() && arr[j] <= ai)
        {
            trie->insert(arr[j]);
            j++;
        }
        if (j == 0)
            ans[ind] = -1;
        else
            ans[ind] = trie->maxXOR(xi);
    }
    return ans;
}

int main()
{
}
