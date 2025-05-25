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
            int k = (num & (1 << i));
            if (k)
            {
                k = 1;
            }
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

int main()
{

    Trie *trie = new Trie();

    vector<int> v = {9, 8, 7, 5, 4};
    for (int i : v)
    {
        trie->insert(i);
    }
    cout << (trie->maxXOR(7));
    return 0;
}