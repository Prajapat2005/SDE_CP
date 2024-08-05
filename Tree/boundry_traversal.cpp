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

bool isLeaf(Node *root)
{
    return (root->right == NULL && root->left == NULL);
}

void addLeft(Node *root, vector<int> &ans)
{

    Node *curr = root;
    while (curr)
    {

        if (!isLeaf(curr))
        {
            ans.push_back(curr->value);
        }

        if (curr->left != NULL)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void addLeaf(Node *root, vector<int> &ans)
{

    if (isLeaf(root))
    {
        ans.push_back(root->value);
        return;
    }

    if (root->left != NULL)
        addLeaf(root->left, ans);
    if (root->right != NULL)
        addLeaf(root->right, ans);
}

void addRight(Node *root, vector<int> &ans)
{
    vector<int> temp;
    Node *curr = root->right;
    while (curr)
    {

        if (!isLeaf(curr))
        {
            temp.push_back(curr->value);
        }

        if (curr->right != NULL)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->right;
        }
    }

    for (int i = temp.size() - 1; i >= 0; --i)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> boundry(Node *root)
{

    if (root == NULL)
        return {};

    vector<int> ans;

    addLeft(root, ans);
    addLeaf(root, ans);
    addRight(root, ans);

    return ans;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> v = boundry(root);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}