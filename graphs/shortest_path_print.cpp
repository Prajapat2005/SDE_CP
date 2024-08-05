#include<bits/stdc++.h>
using namespace std;

vector<int> min_path(vector<pair<int,int>> adj[],int n){

    vector<int> ans(n+1,INT_MAX);
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++) parent[i]=i;

    ans[0]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

    q.push({0,0});
    while(!q.empty()){

        int l=q.top().first;
        int k=q.top().second;
        q.pop();
        for(int i=0;i<adj[k].size();i++){

            int count=adj[k][i].second+l;

            if(ans[adj[k][i].first]>count){

                parent[adj[k][i].first]=k;

                ans[adj[k][i].first]=count;
                q.push({count,adj[k][i].first});

            }
        }

    }
    return parent;

}

//0---->n

int main(){

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){

        int n1,n2,weight;
        cin>>n1>>n2>>weight;
        adj[n1-1].push_back({n2-1,weight});
        adj[n2-1].push_back({n1-1,weight});

    }
    vector<int> parent=min_path(adj,n);
    
    vector<int> ans;
    
    ans.push_back(n);

    while(parent[ans[ans.size()-1]]!=0){

        ans.push_back(parent[ans[ans.size()-1]]);

    }
    ans.push_back(0);
    
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    
}