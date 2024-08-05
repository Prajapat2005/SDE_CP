#include <iostream>
#include<queue>
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
int leafnode(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return (leafnode(root->left)+leafnode(root->right));
}    
int main() {
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->left=new Node(3);
    root->left->left->left->left=new Node(3);
    root->left->left->right=new Node(3);
    cout<<leafnode(root);
       return 0;
}
