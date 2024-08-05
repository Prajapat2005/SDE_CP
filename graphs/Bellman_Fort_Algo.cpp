#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(vector<pair<int,pair<int,int>>>adj ,int n){

    vector<int> dis(n+1,INT_MAX);
    dis[0]=0;
    for(int i=0;i<n;i++){  // n iterations

        for(int j=0;j<adj.size();j++){

            int u = adj[j].first;
            int v = adj[j].second.first;
            int wt = adj[j].second.second;

            if(dis[u]+wt<dis[v]){
                dis[v]=dis[u]+wt;
            }

        }

    }

    return dis;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> adj;
    for(int i=0;i<m;i++){
        int n1,n2,weight;
        cin>>n1>>n2>>weight;
        adj.push_back({n1,{n2,weight}});
    }
    
    vector<int> ans=bellman_ford(adj,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

} 