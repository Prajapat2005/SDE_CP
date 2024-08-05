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
void inorder_traversal(Node* head){
    if(head==NULL) return;
    inorder_traversal(head->left);
    cout<<head->value;
    inorder_traversal(head->right);
}
void preorder_traversal(Node* head){
    if(head==NULL) return;
    cout<<head->value;
    preorder_traversal(head->left);
    preorder_traversal(head->right);
}
void postorder_traversal(Node* head){
    if(head==NULL) return;
    postorder_traversal(head->left);
    postorder_traversal(head->right);
    cout<<head->value;
}
void BFS(Node* head){
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
void preorder_traversal_using_queue(Node* head){
    if(head==NULL) return;
    stack<Node*> s;
    s.push(head);
    while(s.empty()!=true){
        Node* temp=s.top();
        s.pop();
        cout<<temp->value;
        if(temp->right!=NULL) s.push(temp->right);
        if(temp->left!=NULL) s.push(temp->left);
    }
}
int max_height(Node*head){
    if(head==NULL) return 0;
    int l=max_height(head->left);
    int r=max_height(head->right);
    return max(l,r)+1;
}
int diameter(Node*head,int &dia){
    if(head==NULL) return 0;
    int l=diameter(head->left,dia);
    int r=diameter(head->right,dia);
    dia=max(l+r+1,dia);
    return max(l,r)+1;
}
int max_sum_path(Node*head,int &sum){
    if(head==NULL) return 0;
    int l=max_sum_path(head->left,sum);
    int r=max_sum_path(head->right,sum);
    sum=max(sum,l+r+head->value);
    return max(l,r)+head->value;
}
void zig_zag_traversal(Node* head){
    if(head==NULL) return;
    queue<Node*> q;
    stack<Node*> s;
    s.push(head);
    bool flag=true;
    while(q.empty()==false||s.empty()==false){
        if(flag==true){
            int level=s.size();
            while(level--){
            Node* temp=s.top();
            s.pop();
            cout<<temp->value;
            if(temp->right!=NULL) q.push(temp->right);
            if(temp->left!=NULL) q.push(temp->left);
            }
            flag=false;
        }
        else{
            int level=q.size();
            while(level--){
            Node* temp=q.front();
            q.pop();
            cout<<temp->value;
            if(temp->right!=NULL) s.push(temp->right);
            if(temp->left!=NULL) s.push(temp->left);
            }
            flag=true;
        }
    }
}
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
void left_view(Node* head,int level,vector<int> &v){
    if(head==NULL) return ;
    if(level==v.size()) v.push_back(head->value);
    left_view(head->left,level+1,v);
    left_view(head->right,level+1,v);
}

bool search(Node* head,int n,vector<int> &v){
    if(head==NULL){
        return false;
    }
    
    v.push_back(head->value);
    if(head->value==n){
        return true;
    }
    
    if(search(head->left,n,v)==true||search(head->right,n,v)==true) return true;
    
    v.pop_back();
    return false;
}

int Oldest_common_ancestor(Node* head,int n,int m){
    if(head==NULL){
        return -1;
    }
    if(head->value==n||head->value==m) return head->value;
    int l = Oldest_common_ancestor(head->left,n,m);
    int r = Oldest_common_ancestor(head->right,n,m);
    if(l==-1&&r!=-1) return r;
    else if(l!=-1&&r==-1) return l;
    else if(l==-1&&r==-1) return -1;
    else return head->value;
}
int max_width(Node* head){
    queue<pair<Node*,int>> q;
    int ans=1;
    q.push({head,0});
    int front,last;
    while(!q.empty()){
        int size=q.size();
        int x_min=q.front().second;
        for(int i=0;i<size;i++){
        Node* temp = q.front().first;
        int curr_x=q.front().second-x_min;
        if(i==0) front=curr_x;
        if(i==size-1) last=curr_x;
        if(temp->left!=NULL) q.push({temp->left,curr_x*2+1});
        if(temp->right!=NULL) q.push({temp->right,curr_x*2+2});
        }
        ans=max(ans,last-front+1);
    }
    return ans;
}
map<Node*,Node*> bfs(Node* head){
    queue<Node*> q;
    q.push(head);
    map<Node*,Node*> v;
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->left!=NULL){ 
            q.push(temp->left);
            v[temp->left]=temp;
        }
        if(temp->right!=NULL){ 
            q.push(temp->right);
            v[temp->right]=temp;
        }
    }
    return v;
}
queue<Node*> Node_at_distance_k(Node* head,Node* node,int dis){
    map<Node*,Node*> parent_track=bfs(head);
    queue<Node*> ans;
    ans.push(node);
    int d=0;
    map<Node*,bool> visited;
    visited[node]=true;
    while(!ans.empty()){
        int size=ans.size();
        for(int i=0;i<size;i++){
            Node* temp=ans.front();
            ans.pop();
            if(temp->left!=NULL && !visited[temp->left]){
                visited[temp->left]=true;
                 ans.push(temp->left);
            }
            if(temp->right!=NULL && !visited[temp->right]){
                visited[temp->right]=true;
                 ans.push(temp->right);
            }
            if(parent_track[temp]&& !visited[parent_track[temp]]){
                visited[parent_track[temp]]=true;
                 ans.push(parent_track[temp]);
            }
        }
        d++;
        if(d==dis) break;
    }
    return ans;
}
int left_height(Node*head){
    if(head==NULL) return 0;
    int count=0;
    while(head){
       count++;
       head=head->left;
    }
    return count;
}
int right_height(Node*head){
    if(head==NULL) return 0;
    int count=0;
    while(head){
       count++;
       head=head->right;
    }
    return count;
}
int number_of_nodes(Node* head){
    if(head==NULL) return 0;
    int lh = left_height(head);
    int rh = right_height(head);
    if(lh!=rh) return 1+number_of_nodes(head->left)+number_of_nodes(head->right);
    if(lh==rh) return pow(2,lh)-1;
    
}
int main() {
    Node* head= new Node(1);
    head->left= new Node(2);
    head->right=new Node(3);
    head->left->left=new Node(4);
    head->left->right=new Node(5);
    head->left->right->left=new Node(6);
    head->left->right->right=new Node(7);
    head->right->right=new Node(9);
    head->right->left=new Node(8);
    cout<<number_of_nodes(head);
    return 0;
}