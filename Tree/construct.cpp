#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int x)
    {
        value = x;
        left = NULL;
        right = NULL;
    }
};

Node *tree(vector<int> preorder, int startPRE, int endPRE, vector<int> inorder, int startIN, int endIN, map<int, int> mp)
{

    if (startPRE > endPRE || startIN > endIN)
        return NULL;

    Node *root = new Node(preorder[startPRE]);

    int Root = mp[root->value];
    int numsLeft = Root - startIN;

    root->left = tree(preorder, startPRE + 1, startPRE + numsLeft, inorder, startIN, Root - 1, mp);

    root->right = tree(preorder, startPRE + numsLeft + 1, endPRE, inorder, Root + 1, endIN, mp);

    return root;
}
Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{

    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    return tree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
}

// inorder postorde

Node *buildTreePostIn(vector<int> &inorder, int startIN, int endIN,
                      vector<int> &postorder, int startPost, int endPost, map<int, int> &hm)
{

    if (startPost > endPost || startIN > endIN)
    {
        return NULL;
    }

    // Create a new Node
    // with the root value from postorder
    Node *root = new Node(postorder[endPost]);

    // Find the index of the root
    // value in inorder traversal
    int inRoot = hm[postorder[endPost]];

    // Number of nodes in the left subtree
    int numsLeft = inRoot - startIN;

    // Recursively build the
    // left and right subtrees
    root->left = buildTreePostIn(inorder, startIN, inRoot - 1, postorder,
                                 startPost, startPost + numsLeft - 1, hm);

    root->right = buildTreePostIn(inorder, inRoot + 1, endIN, postorder,
                                  startPost + numsLeft, endPost - 1, hm);

    // Return the root of
    // the constructed subtree
    return root;
}
Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() != postorder.size())
    {
        return NULL;
    }
    map<int, int> hm;
    for (int i = 0; i < inorder.size(); i++)
    {
        hm[inorder[i]] = i;
    }
    return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
                           postorder.size() - 1, hm);
}
