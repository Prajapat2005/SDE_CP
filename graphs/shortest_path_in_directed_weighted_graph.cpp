#include<bits/stdc++.h>
using namespace std;

void topological(vector<pair<int,int>>adj[],int z,vector<int>&visited,stack<int>&s){

    visited[z]=1;
    for(int i=0;i<adj[z].size();i++){

     if(visited[adj[z][i].first]==0) topological(adj,adj[z][i].first,visited,s);

    }

    s.push(z);

}

stack<int> topological_sorting(vector<pair<int,int>> adj[],int n){

    vector<int> visited(n+1,0);
    stack<int>s;
    for(int i=0;i<=n;i++){
        if(visited[i]==0) topological(adj,i,visited,s);
    }
     
    return s;

}

vector<int> shortest_path(vector<pair<int,int>> adj[],stack<int> s,int n,int z){
     
    vector<int> ans(n+1,INT_MAX);
    ans[z]=0;
    while(!s.empty()){
        int k = s.top();
        s.pop();

        for(int i=0;i<adj[k].size();i++){
            int weight=adj[k][i].second;
            weight=weight+ans[k];
            ans[adj[k][i].first]=min(ans[adj[k][i].first],weight);
        }

    }
    
    return ans;

}

int main(){

   int n,m,source;
   cin>>n>>m>>source;
   vector<pair<int,int>> adj[n+1];
   for(int i=0;i<m;i++){
    int n1,n2,w;
    cin>>n1>>n2>>w;
    adj[n1].push_back({n2,w});
   }

   stack<int> s =topological_sorting(adj,n);
   vector<int> ans=shortest_path(adj,s,n,source);

   for(int i=0;i<=n;i++){
    cout<<ans[i]<<" ";
   }
}