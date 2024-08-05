#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> v,vector<vector<int>> &visit,int i,int j,int n,int m){ 

     queue<pair<int,int>>q; 
     q.push({i,j}); 
     visit[i][j]=1;
     while(!q.empty()){
        int k,l;
        k=q.front().first;
        l=q.front().second;
        q.pop();
        if(k>=1&&visit[k-1][l]==0&&v[k-1][l]==1){ 
            q.push({k-1,l});   
            visit[k-1][l]=1; 
            
        }
        if(l+1<m&&visit[k][l+1]==0&&v[k][l+1]==1){ 
            q.push({k,l+1});  
            visit[k][l+1]=1;  
            
        }
        if(k+1<n&&visit[k+1][l]==0&&v[k+1][l]==1){ 
            q.push({k+1,l});   
            visit[k+1][l]=1; 
            
        }
        if(l-1>=0&&visit[k][l-1]==0&&v[k][l-1]==1){ 
            q.push({k,l-1});  
            visit[k][l-1]=1;  
            
        }
        if(k+1<n&&l+1<m&&visit[k+1][l+1]==0&&v[k+1][l+1]==1){ 
            q.push({k+1,l+1});  
            visit[k+1][l+1]=1; 
            
        }
        if(k+1<n&&l-1>=0&&visit[k+1][l-1]==0&&v[k+1][l-1]==1){ 
            q.push({k+1,l-1});  
            visit[k+1][l-1]=1; 
            
        }
        if(k-1>=0&&l+1<m&&visit[k-1][l+1]==0&&v[k-1][l+1]==1){ 
            q.push({k-1,l+1});  
            visit[k-1][l+1]=1; 
            
        }
        if(k-1>=0&&l-1>=0&&visit[k-1][l-1]==0&&v[k-1][l-1]==1){ 
            q.push({k-1,l-1}); 
            visit[k-1][l-1]=1; 
            
        }

      } 
}

int number_of_conponents(vector<vector<int>> v,vector<vector<int>> &visit,int n,int m){
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==1&&visit[i][j]==0){ 
                dfs(v,visit,i,j,n,m);
                count++;
            }

        }
    }
    return count;
}

int main(){
   
   int n,m;
   cin>>n>>m;
   vector<vector<int>> v(n,vector<int>(m));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cin>>v[i][j];
   }
    vector<vector<int>> visit(n,vector<int>(m,0));
   cout<<number_of_conponents(v,visit,n,m);


}