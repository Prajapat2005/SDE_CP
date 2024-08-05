#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *right;
    Node *left;
    Node(int x)
    {
        value = x;
        right = NULL;
        left = NULL;
    }
};

/*     1
     2   3
    4 5 6 7

    4 2 5 1 6 3 7
    Left Root Right */
void inorder_traversal(Node *head)
{
    if (head == NULL)
        return;
    inorder_traversal(head->left);
    cout << head->value;
    inorder_traversal(head->right);
}

/*     1
     2   3
    4 5 6 7

    1 2 4 5 3 6 7
    Root Left Right */
void preorder_traversal(Node *head)
{
    if (head == NULL)
        return;
    cout << head->value;
    preorder_traversal(head->left);
    preorder_traversal(head->right);
}
void preorder_traversal_using_stack(Node *head)
{
    if (head == NULL)
        return;
    stack<Node *> s;
    s.push(head);
    while (s.empty() != true)
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->value;
        if (temp->right != NULL)
            s.push(temp->right);
        if (temp->left != NULL)
            s.push(temp->left);
    }
}

/*     1
     2   3
    4 5 6 7

    4 5 2 6 7 3 1
    Left Right Root*/
void postorder_traversal(Node *head)
{
    if (head == NULL)
        return;
    postorder_traversal(head->left);
    postorder_traversal(head->right);
    cout << head->value;
}

vector<vector<int>> pre_in_post(Node *head)
{

    stack<pair<Node *, int>> s;
    s.push({head, 1});
    vector<int> pre, ino, post;

    while (!s.empty())
    {
        Node *temp = s.top().first;
        int num = s.top().second;
        s.pop();

        if (num == 1)
        {
            pre.push_back(temp->value);
            s.push({temp, num + 1});
            if (temp->left != NULL)
                s.push({temp->left, 1});
        }
        else if (num == 2)
        {
            ino.push_back(temp->value);
            s.push({temp, num + 1});
            if (temp->right != NULL)
                s.push({temp->right, 1});
        }
        else
        {
            post.push_back(temp->value);
        }
    }
    vector<vector<int>> ans;
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}

int main()
{
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    inorder_traversal(head);
    cout << "\n";
    preorder_traversal(head);
    cout << "\n";
    postorder_traversal(head);
    return 0;
}
