/* https://cses.fi/problemset/task/1731/ */
#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    vector<Node *> links;
    int end;

public:
    Node()
    {
        links.resize(26);
        end = 0;
    }
    bool containsKey(char &ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char &ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char &ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        end = 1;
    }
    int getEnd()
    {
        return end;
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
    void update(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    int search(string word, int x, vector<int> &dp)
    {

        Node *node = root;
        int ans = 0;
        for (int i = x; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return ans;
            }
            node = node->get(word[i]);
            if (node->getEnd())
            {
                ans = (ans + dp[i + 1]) % 1000000007;
            }
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    int n;
    cin >> n;
    Trie *trie = new Trie();
    while (n--)
    {
        string s1;
        cin >> s1;
        trie->update(s1);
    }

    vector<int> dp(s.length() + 1);
    dp[s.length()] = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        dp[i] = trie->search(s, i, dp);
    }
    cout << dp[0];
    return 0;
}
