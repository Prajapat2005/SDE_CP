#include <iostream>
using namespace std;
class Node{
public: 
      int value;
      Node* left;
      Node* right;
      Node(int x){
          value=x;
          left=NULL;
          right=NULL;
      }
};
class BST{
public:
   Node*root; 
   BST(){
       root=NULL;
   }
};

void insert_BST(Node* &root , int k){
    Node* newnode= new Node(k);
    if(root==NULL){
        root=newnode;
        return;
    }
    Node* curr=root;
    while(true){
        if(curr->value>k){
            if(curr->left==NULL){
                curr->left=newnode;
                return;
            }
            curr=curr->left;
        }
        else {
            if(curr->right==NULL){
                curr->right=newnode;
                return;
            }
            curr=curr->right;
        }
    }
}

Node* largest_node(Node* root){
    Node* curr=root;
    while(curr && curr->right!=NULL){
        curr=curr->right;
    }
    return curr;
}

Node* delete_BST(Node* root, int k){
    if(root==NULL)  return root;
    if(root->value>k)  root->left= delete_BST(root->left,k);
    else if(root->value<k)  root->right= delete_BST(root->right,k);
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node* justsmallernode = largest_node(root->left);
            root->value=justsmallernode->value;
            root->left=delete_BST(root->left,justsmallernode->value);
        }
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}
int main() {
    BST bst1;
    insert_BST(bst1.root,3);
    insert_BST(bst1.root,1);
    insert_BST(bst1.root,4);
    insert_BST(bst1.root,6);
    insert_BST(bst1.root,2);
    inorder(bst1.root);
    bst1.root=delete_BST(bst1.root,3);
    inorder(bst1.root);
    return 0;
}