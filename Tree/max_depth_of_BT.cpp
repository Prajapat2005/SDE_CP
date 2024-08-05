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

int max_depth(Node *root)
{
    if (root == NULL)
        return 0;
    int l = max_depth(root->left);
    int r = max_depth(root->right);
    return max(l, r) + 1;
}

/* if it return -1 means not balance otherwise it is balance */
int Balance_Binary_Tree(Node *root)
{
    if (root == NULL)
        return 0;
    int l = max_depth(root->left);
    int r = max_depth(root->right);
    if (l == -1 || r == -1)
        return -1;
    if (abs(l - r) > 1)
        return -1;
    return max(l, r) + 1;
}
/* diameter max distance between any two node */
int diameter(Node *head, int &dia)
{
    if (head == NULL)
        return 0;
    int l = diameter(head->left, dia);
    int r = diameter(head->right, dia);
    dia = max(l + r + 1, dia);
    return max(l, r) + 1;
}
/* max path sum */
int max_sum(Node *root, int &sum)
{

    if (root == NULL)
        return 0;

    int l = max_sum(root->left, sum);
    int r = max_sum(root->right, sum);

    sum = max(sum, l + r + root->value);

    if (max(l, r) < 0 && root->value > 0)
        return root->value;
    else if (max(l, r) + root->value < 0)
        return 0;
    return root->value + max(l, r);
}

int left_height(Node *head)
{
    if (head == NULL)
        return 0;
    int count = 0;
    while (head)
    {
        count++;
        head = head->left;
    }
    return count;
}
int right_height(Node *head)
{
    if (head == NULL)
        return 0;
    int count = 0;
    while (head)
    {
        count++;
        head = head->right;
    }
    return count;
}
// number of nodes in complete BT, all nodes filled but leaf nodes may or may not, but they are left as possible
int number_of_nodes(Node *head)
{
    if (head == NULL)
        return 0;
    int lh = left_height(head);
    int rh = right_height(head);
    if (lh != rh)
        return 1 + number_of_nodes(head->left) + number_of_nodes(head->right);
    if (lh == rh)
        return pow(2, lh) - 1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(3);
    root->left->left->left->left = new Node(3);
    root->left->left->right = new Node(3);
    cout << max_depth(root);
    return 0;
}
/* 5 */