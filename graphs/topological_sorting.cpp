#include<bits/stdc++.h>
using namespace std;

void topological(vector<int>adj[],int z,vector<int>&visited,stack<int>&s){

    visited[z]=1;
    for(int i=0;i<adj[z].size();i++){

     if(visited[adj[z][i]]==0) topological(adj,adj[z][i],visited,s);

    }

    s.push(z);

}

vector<int> topological_sorting(vector<int> adj[],int n){

    vector<int> visited(n+1,0);
    stack<int>s;
    for(int i=0;i<=n;i++){
        if(visited[i]==0) topological(adj,i,visited,s);
    }
     
    vector<int> ans;
    while(!s.empty()){
        int l=s.top();
        s.pop();
        ans.push_back(l);
    }
    return ans;
}

vector<int> kahn_algorithm(vector<int> adj[],int n){

    queue<int>q;
    vector<int> v(n+1,0);
    for(int i=0;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            v[adj[i][j]]++;
        }
    }
    for(int i=0;i<n+1;i++){
        if(v[i]==0) q.push(i);
    }
    
    vector<int> ans;

    while(!q.empty()){

        int z=q.front();
        q.pop();

        for(int i=0;i<adj[z].size();i++){

            v[adj[z][i]]--;
            if(v[adj[z][i]]==0) q.push(adj[z][i]);

        }

        ans.push_back(z);

    }

    return ans;

}

int main(){

   int n,m;
   cin>>n>>m;
   vector<int> adj[n+1];
   for(int i=0;i<m;i++){
    int n1,n2;
    cin>>n1>>n2;
    adj[n1].push_back(n2);
   }

   vector<int>ans=kahn_algorithm(adj,n);
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }

}