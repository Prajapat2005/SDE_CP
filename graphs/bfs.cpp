#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<int> adj[] ){
    vector<int> ans;

    vector<int> vis(n+1,0); // one base indexing is zero then size is n
    vis[1]=1;     // starting node
    queue<int> q;
    q.push(1);
    while(!q.empty()){
       int n=q.front();
       q.pop();
       ans.push_back(n);
       for(int i=0;i<adj[n].size();i++){
        if(vis[adj[n][i]]!=1) q.push(adj[n][i]);
         vis[adj[n][i]]=1;
       }  

    }
     return ans;
}

int main(){

   int n,m;
   cin>>n>>m;
   vector<int> adj[n+1];
   for(int i=1;i<=m;i++){
    int n1,n2;
    cin>>n1>>n2;
    adj[n1].push_back(n2);
    adj[n2].push_back(n1);
   }

   vector<int> ans=bfs(n,adj);
   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}

/*
8 8
1 2
1 6
2 3
2 4
6 7
6 8
4 5
7 5

1 2 6 3 4 7 8 5 */