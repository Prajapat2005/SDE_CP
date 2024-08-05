#include <bits/stdc++.h>
using namespace std;

int min_sum(vector<vector<int>> v,int n,int i,int j){
      if(i==n-1) return v[i][j];   // when reach to last row
      
      int down=INT_MAX,cross=INT_MAX;
      down = v[i][j] + min_sum(v,n,i+1,j);
      cross = v[i][j] + min_sum(v,n,i+1,j+1);
      
      return min(down,cross);
      
}

// using DP
int min_sum_1(vector<vector<int>> v,vector<vector<int>> dp,int n,int i,int j){
      if(i==n-1) return v[i][j];   // when reach to last row
      
      int down=INT_MAX,cross=INT_MAX;
      if(dp[i+1][j]==-1) dp[i+1][j] = min_sum_1(v,dp,n,i+1,j);
      down = v[i][j] + dp[i+1][j] ;

      if(dp[i+1][j+1]==-1) dp[i+1][j+1] = min_sum_1(v,dp,n,i+1,j+1);
      cross = v[i][j] + dp[i+1][j+1];
      
      return min(down,cross);
      
}

//without using extra space
int min_sum(vector<vector<int>> v,int n){
     vector<int> future(n+1,0);
     for(int i=n-1;i>=0;i--){
         vector<int> curr(i+1,0);
         for(int j=i;j>=0;j--){
              
            if(i==n-1) curr[j]=v[i][j];
            else{
                int down = v[i][j] + future[j];
                int cross = v[i][j] + future[j+1];
                
                curr[j]=min(down,cross);
            }
             
         }
         future=curr;
     }
     return future[0];
}


int main() {
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>v[i][j];
    }
    cout<<min_sum(v,n,0,0);

    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<min_sum_1(v,dp,n,0,0);
    return 0;
}