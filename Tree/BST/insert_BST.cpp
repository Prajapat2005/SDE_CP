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

void insertBST(Node* &root , int k){
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
Node* insertBST2(Node* root, int val){
    if(root==NULL){
        Node* newnode= new Node(val);
        return newnode;
    }
    if(root->value>val){
        root->left = insertBST2(root->left,val);
    }
    else if(root->value<val){
        root->right= insertBST2(root->right,val);
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
    insertBST(bst1.root,3);
    insertBST(bst1.root,1);
    insertBST(bst1.root,4);
    insertBST(bst1.root,6);
    insertBST(bst1.root,2);
    inorder(bst1.root);
    return 0;
}

/*       3  
      1     4
        2     6

        1 2 3 4 6 */