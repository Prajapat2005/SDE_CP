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
bool search(Node *head, int n, vector<int> &v)
{
    if (head == NULL)
    {
        return false;
    }

    v.push_back(head->value);
    if (head->value == n)
    {
        return true;
    }
    /*if both either left or right return true it return true if not then it
    pop that element and return false*/
    if (search(head->left, n, v) == true || search(head->right, n, v) == true)
        return true;

    v.pop_back();
    return false;
}

int Oldest_common_ancestor(Node *head, int n, int m)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->value == n || head->value == m)
        return head->value;
    int l = Oldest_common_ancestor(head->left, n, m);
    int r = Oldest_common_ancestor(head->right, n, m);
    if (l == -1 && r != -1)
        return r; // left null right not return right
    else if (l != -1 && r == -1)
        return l; // right null right not return left
    else if (l == -1 && r == -1)
        return -1; // both return null return null
    else
        return head->value; // both are not null then return node value(this is ancestor)
}

int max_width(Node *head)
{
    queue<pair<Node *, int>> q;
    int ans = 1;
    q.push({head, 0});
    int front, last;

    while (!q.empty())
    { // loop for every level
        int size = q.size();
        int x_min = q.front().second;
        // to subtract for every index of that level. It is 0 for top most other wise it is always 1

        for (int i = 0; i < size; i++)
        { // loop for perticular level
            Node *temp = q.front().first;
            int curr_x = q.front().second - x_min;
            q.pop();
            if (i == 0)
                front = curr_x;
            if (i == size - 1)
                last = curr_x;
            if (temp->left != NULL)
                q.push({temp->left, curr_x * 2 + 1});
            if (temp->right != NULL)
                q.push({temp->right, curr_x * 2 + 2});
        }
        ans = max(ans, last - front + 1); // ever level max width
    }
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
    vector<int> v;
    search(head, 6, v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}