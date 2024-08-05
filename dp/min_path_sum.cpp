#include <bits/stdc++.h>
using namespace std;


// same concept as to find total path
int min_sum(vector<vector<int>>v,int i,int j){
     
     if(i==0&&j==0)  return v[0][0];
     
      int up=INT_MAX,left=INT_MAX;    // for max up=0 , left=0

      if(i-1>=0) up= v[i][j]+ min_sum(v,i-1,j);
      if(j-1>=0) left=v[i][j]+ min_sum(v,i,j-1);

      return min(up,left);
       
}

// using DP
int min_sum_1(vector<vector<int>> v,vector<vector<int>> dp,int i,int j){
     
     if(i==0&&j==0)  return v[0][0];
     
      int up=INT_MAX,left=INT_MAX;    // for max up=0 , left=0

      if(i-1>=0){ 
        if(dp[i-1][j]==-1) dp[i-1][j] = min_sum_1(v,dp,i-1,j);
        up = v[i][j] + dp[i-1][j];
      }

      if(j-1>=0){  
        if(dp[i][j-1]==-1) dp[i][j-1] = min_sum_1(v,dp,i,j-1);
        left = v[i][j] + dp[i][j-1];
      }

      return min(up,left);
       
}

//without using extra space;
int min_sum_2(vector<vector<int>> v,int i,int j){
    vector<int> pre(j+1,0);
    for(int k=0;k<=i;k++){
        vector<int> curr(j+1,0);
        for(int l=0;l<=j;l++){

            if(l==0 && k==0) curr[l]=v[k][l];
            else{
                int up=INT_MAX,left=INT_MAX;
                if(k>0)up = v[k][l] + pre[l];
                if(l>0)left = v[k][l] + curr[l-1];

                curr[l]=min(up,left);
            }

        }
        pre=curr;
    }
    return pre[j];
}

int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>v[i][j];
    }
    cout<<min_sum(v,n-1,m-1);

    vector<vector<int>> dp(n,vector<int>(m));
    cout<<min_sum_1(v,dp,n-1,m-1);
    return 0;
}