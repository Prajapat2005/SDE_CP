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

vector<vector<int>> zig_zag_traversal(Node *root)
{

    stack<Node *> s;
    s.push(root);
    vector<int> v;
    vector<vector<int>> ans;

    bool flag = true;

    while (!s.empty())
    {
        stack<Node *> s2;
        if (flag == true)
        {
            int n = s.size();
            while (n--)
            {
                Node *temp = s.top();
                s.pop();
                if (temp->left != NULL)
                    s2.push(temp->left);
                if (temp->right != NULL)
                    s2.push(temp->right);

                v.push_back(temp->value);
            }
            flag = false;
        }
        else
        {
            int n = s.size();
            while (n--)
            {
                Node *temp = s.top();
                s.pop();
                if (temp->right != NULL)
                    s2.push(temp->right);
                if (temp->left != NULL)
                    s2.push(temp->left);

                v.push_back(temp->value);
            }
            flag = true;
        }
        ans.push_back(v);
        v.clear();
        s = s2;
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
    vector<vector<int>> ans = zig_zag_traversal(head);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}