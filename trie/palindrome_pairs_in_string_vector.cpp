class Node
{
public:
    vector<Node *> links;
    int end;
    vector<int> palindrome_below;
    Node()
    {
        links.resize(26);
        end = -1;
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
    void setEnd(int &i)
    {
        end = i;
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
    vector<vector<int>> ans;

public:
    Trie()
    {
        root = new Node();
    }
    bool check(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
    void update(string &s, int &ind)
    {
        Node *node = root;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (check(s, 0, i))
            {
                node->palindrome_below.push_back(ind);
            }
            if (!node->containsKey(s[i]))
            {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
        node->setEnd(ind);
        node->palindrome_below.push_back(ind);
    }
    void search(string &s, int &ind)
    {
        Node *node = root;
        for (int i = 0; i < s.length(); i++)
        {
            if ((node->getEnd() != -1) && (node->getEnd() != ind) && (check(s, i, s.length() - 1)))
            {
                ans.push_back({ind, node->getEnd()});
            }
            if (!node->containsKey(s[i]))
            {
                return;
            }
            node = node->get(s[i]);
        }
        for (int i = 0; i < node->palindrome_below.size(); i++)
        {
            if (node->palindrome_below[i] != ind)
            {
                ans.push_back({ind, node->palindrome_below[i]});
            }
        }
    }
    vector<vector<int>> solve()
    {
        return ans;
    }
};

vector<vector<int>> palindromePairs(vector<string> &v)
{

    Trie *trie = new Trie();
    for (int i = 0; i < v.size(); i++)
    {
        trie->update(v[i], i);
    }

    for (int i = 0; i < v.size(); i++)
    {
        trie->search(v[i], i);
    }

    return trie->solve();
}

int main()
{
}