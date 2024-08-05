#include <bits/stdc++.h>
using namespace std;
class Node{
    public :
          int value;
          Node* right;
          Node* left;
          Node(int x){
              value=x;
              right=NULL;
              left=NULL;
          }
};

/* mp<vertical<level,{nodes}>>
  q(node,(vertical,level))  */
vector<vector<int>> vertical_traversal(Node*head){
    map<int,map<int,multiset<int>>> mp;
    queue<pair<Node*,pair<int,int>>> q;
    q.push({head,{0,0}});
    while(q.empty()!=true){
        Node* temp=q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        if(temp->left!=NULL) q.push({temp->left,{x-1,y+1}});
        if(temp->right!=NULL) q.push({temp->right,{x+1,y+1}});
        q.pop();
        mp[x][y].insert(temp->value);
    }
    vector<vector<int>> ans;
    for(auto i:mp){
        vector<int> column;
        for(auto z:i.second){
            column.insert(column.end(),z.second.begin(),z.second.end());
        }
        ans.push_back(column);
    }
    return ans;
    
}

/*    first element of all verticals 
      mp<vertical,node value>
      q({node,vertical})      */
      
void top_view(Node*head){
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({head,0});
    while(q.empty()!=true){
        Node* temp=q.front().first;
        int x = q.front().second;
        if(temp->left!=NULL) q.push({temp->left,x-1});
        if(temp->right!=NULL) q.push({temp->right,x+1});
        if(mp.find(x)==mp.end()) mp[x]=temp->value;
        q.pop();
    }
    for(auto it:mp){
        cout<<it.second<<" ";
    }
}

/*    last element of all verticals 
      mp<vertical,node value>
      q({node,vertical})      */
void bottom_view(Node*head){
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({head,0});
    while(q.empty()!=true){
        Node* temp=q.front().first;
        int x = q.front().second;
        if(temp->left!=NULL) q.push({temp->left,x-1});
        if(temp->right!=NULL) q.push({temp->right,x+1});
        mp[x]=temp->value;
        q.pop();
    }
    for(auto it:mp){
        cout<<it.second<<" ";
    }
}

/* right most element of same level 
    root right left */
void right_view(Node* head,int level,vector<int> &v){
    if(head==NULL) return ;
    if(level==v.size()) v.push_back(head->value);
    right_view(head->right,level+1,v);
    right_view(head->left,level+1,v);
}

/*  left most element of same level 
    root left left */
void left_view(Node* head,int level,vector<int> &v){
    if(head==NULL) return ;
    if(level==v.size()) v.push_back(head->value);
    left_view(head->left,level+1,v);
    left_view(head->right,level+1,v);
}
int main() {
    Node* head= new Node(1);
    head->left= new Node(2);
    head->right=new Node(3);
    head->left->left=new Node(4);
    head->left->right=new Node(5);
    head->right->left=new Node(6);
    head->right->right=new Node(7);
    vector<vector<int>> v=vertical_traversal(head);
    return 0;
}