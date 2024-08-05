#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    Node* left;
    Node* right;
    Node(int x){
        value =x;
        left=NULL;
        right=NULL;
    }
};
void level_order_traversal(Node* head){
    if(head==NULL) 
      return;
    queue<Node*> q;
    q.push(head);
    while(q.empty()!=true){
        Node* temp=q.front();
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
        cout<<temp->value;
        q.pop();
    }
}

int main() {
    Node *head= new Node(1);
    head->left=new Node(2);
    head->right=new Node(3);
    head->left->left=new Node(4);
    head->left->right=new Node(5);
    head->right->left=new Node(6);
    head->right->right=new Node(7);
    level_order_traversal(head);
    return 0;
}
