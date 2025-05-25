#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Trie Node Structure
struct TrieNode
{
    vector<TrieNode *> children;
    int count; // Count of words passing through this node

    TrieNode() : children(26, nullptr), count(0) {}
};

// Trie Class
class Trie
{
private:
    TrieNode *root;

public:
    Trie() { root = new TrieNode(); }

    // Insert a title into the trie
    void insert(const string &title)
    {
        TrieNode *node = root;
        for (char c : title)
        {
            int index = c - 'a';
            if (node->children[index] == nullptr)
            {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            node->count++; // Increment count for this node
        }
    }

    // Count prefixes for a given title
    int countPrefixes(const string &title)
    {
        TrieNode *node = root;
        int prefixCount = 0;
        for (char c : title)
        {
            int index = c - 'a';
            if (node->children[index] == nullptr)
                break;
            node = node->children[index];
            prefixCount += node->count;
        }
        return prefixCount;
    }
};

// Function to count pairs where one title is a prefix of another
int countPrefixPairs(const vector<string> &titles)
{
    Trie trie;
    int totalPairs = 0;

    // Insert all titles into the trie
    for (const string &title : titles)
    {
        trie.insert(title);
    }

    // Count prefix pairs
    for (const string &title : titles)
    {
        totalPairs += trie.countPrefixes(title) - 1; // Exclude self-pairing
    }

    return totalPairs / 2; // Each pair is counted twice
}

int main()
{
    // Example titles
    vector<string> titles = {"book", "bo", "boo", "booklet"};

    // Count and display prefix pairs
    int prefixPairs = countPrefixPairs(titles);
    cout << "Number of prefix pairs: " << prefixPairs << endl;

    return 0;
}
