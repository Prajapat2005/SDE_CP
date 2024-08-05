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

/* function for mapping root to its parent <root,parent> using BFS */
map<Node *, Node *> bfs(Node *head)
{
    queue<Node *> q;
    q.push(head);
    map<Node *, Node *> v;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
            v[temp->left] = temp;
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
            v[temp->right] = temp;
        }
    }
    return v;
}

queue<Node *> Node_at_distance_k(Node *head, Node *node, int dis)
{

    map<Node *, Node *> parent_track = bfs(head);
    queue<Node *> q;
    q.push(node); // push target node
    int d = 0;
    map<Node *, bool> visited; // visited map to check weather node is visited or not
    visited[node] = true;      // target node mark visited

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {

            Node *temp = q.front();
            q.pop();

            // for pushing parent node
            if (parent_track[temp] && !visited[parent_track[temp]])
            { // check weither temp's parent exist or not && if exist it is visited or not
                visited[parent_track[temp]] = true;
                q.push(parent_track[temp]);
            }

            // for pushing left node
            if (temp->left != NULL && !visited[temp->left])
            { // check weither temp left exist or not && it is visited or not
                visited[temp->left] = true;
                q.push(temp->left);
            }

            // for pushing right node
            if (temp->right != NULL && !visited[temp->right])
            { // check weither temp left exist or not && it is visited or not
                visited[temp->right] = true;
                q.push(temp->right);
            }
        }
        d++; // after every layer distance ++;
        if (d == dis)
            break;
    }

    return q;
}
int main()
{
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->left->right->left = new Node(6);
    head->left->right->right = new Node(7);
    head->right->right = new Node(9);
    head->right->left = new Node(8);
    queue<Node *> q = Node_at_distance_k(head, head->left, 2);
    while (!q.empty())
    {
        cout << q.front()->value << " ";
        q.pop();
    }
    return 0;
}