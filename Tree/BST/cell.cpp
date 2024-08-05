#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// like binary search
int findCeil(Node *root, int key) // just greater
{
    // Initialize the variable
    // to store the ceiling value
    int ceil = -1;

    // Traverse the BST until reaching
    // the end or finding the key
    while (root)
    {
        // If the key is found, assign it
        // as the ceiling and return
        if (root->val == key)
        {
            ceil = root->val;
            return ceil;
        }

        // If the key is greater,
        // move to the right subtree
        if (key > root->val)
        {
            root = root->right;
        }
        else
        {
            // If the key is smaller, update ceil
            // and move to the left subtree
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}

int floor(Node *root, int x)
{ // just small

    int ans = -1;

    while (root)
    {

        if (root->val == x)
        {
            return x;
        }

        if (root->val < x)
        {
            ans = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return ans;
}