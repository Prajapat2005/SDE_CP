#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
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

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool check(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
                if (node->isEnd() == false)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return node->isEnd();
    }
};

int main()
{
    Trie *trie = new Trie();
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        trie->insert(v[i]);
    }

    string maxi = "";
    for (int i = 0; i < n; i++)
    {
        if (trie->check(v[i]))
        {
            if (maxi.length() < v[i].length())
            {
                maxi = v[i];
            }
            else if (maxi.length() == v[i].length())
            {
                if (maxi > v[i])
                {
                    maxi = v[i];
                }
            }
        }
    }

    cout << maxi;
    return 0;
}