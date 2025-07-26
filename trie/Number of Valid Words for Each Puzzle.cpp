// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/?envType=problem-list-v2&envId=string

class Trie
{
public:
    vector<Trie *> links;
    int end;
    Trie()
    {
        links.resize(26, nullptr);
        end = 0;
    }
};

class Solution
{
public:
    Trie *root;

    void insert(vector<int> freq)
    {

        Trie *temp = root;

        for (int i = 0; i < 26; i++)
        {

            if (!freq[i])
            {
                continue;
            }

            if (temp->links[i] == nullptr)
            {
                temp->links[i] = new Trie();
            }
            temp = temp->links[i];
        }

        temp->end++;
    }

    int dfs(Trie *node, string word, bool taken)
    {

        int cnt = (taken ? (node->end) : 0);

        for (char ch : word)
        {
            if (node->links[ch - 'a'])
            {
                cnt += dfs(node->links[ch - 'a'], word, taken | ch == word[0]);
            }
        }

        return cnt;
    }

    vector<int> findNumOfValidWords(vector<string> &words,
                                    vector<string> &puzzles)
    {

        root = new Trie();

        for (auto it : words)
        {

            vector<int> freq(26, 0);

            for (auto ch : it)
            {
                freq[ch - 'a'] = 1;
            }

            if (accumulate(freq.begin(), freq.end(), 0) <= 7)
                insert(freq);
        }

        vector<int> ans;
        for (auto it : puzzles)
        {
            Trie *dummy = root;
            ans.push_back(dfs(dummy, it, false));
        }

        return ans;
    }
};