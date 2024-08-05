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

bool ans(Node *root, int limit_L, int limit_R)
{

    if (root == NULL)
        return true;

    if (!(root->value <= limit_R && root->value >= limit_L))
        // if node is not in limit then return false
        return false;

    return ans(root->left, limit_L, root->value) && ans(root->right, root->value, limit_R);
}

int main()
{

    Node *head;
    return ans(head, INT_MIN, INT_MAX);
}