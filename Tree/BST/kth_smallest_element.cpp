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

int inorder(Node *root, int &count, int &kth_small)
{

    inorder(root->left, count, kth_small);
    count--;
    if (count == 0)
    {
        kth_small = root->value;
        return;
    }
    inorder(root->left, count, kth_small);

    return;
}

// kth largest
int inorder(Node *root, int &count, int &kth_large)
{

    inorder(root->right, count, kth_large);
    count--;
    if (count == 0)
    {
        kth_large = root->value;
        return;
    }
    inorder(root->right, count, kth_large);

    return;
}