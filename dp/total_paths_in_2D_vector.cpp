#include <bits/stdc++.h>
using namespace std;

// 0----->>>>> n-1 indexing 
int total_path(int i,int j){

   if(i==0&&j==0) return 1;
   
   int p1=0,p2=0;

   if(i-1>=0) p1 = total_path(i-1,j);
   if(j-1>=0) p2 = total_path(i,j-1);

  return p1+p2;

}

 //  using DP store previously solved problem
int total_path1(int i,int j,vector<vector<int>> &dp){
   if(i==0&&j==0) return 1;
   
   int p1=0,p2=0;
   
   if(i-1>=0){ 
       if(dp[i-1][j]==-1) dp[i-1][j]=total_path1(i-1,j,dp);
       p1 = dp[i-1][j];
   }
   
   if(j-1>=0){ 
       if(dp[i][j-1]==-1) dp[i][j-1]=total_path1(i,j-1,dp);
       p2 = dp[i][j-1];
   }

  return p1+p2;
}


// without using extra space
int total_path2(int i,int j){      //  i=n-1 j=m-1
   
   vector<int> prev(j+1,0);

   for(int k=0;k<=i;k++){

       vector<int> temp(j+1,0);

       for(int l=0;l<=j;l++){

          if(k==0&&l==0) temp[l]=1;
          else{
                int p1=0,p2=0;
                if(l>0) p1=temp[l-1];
                if(k>0) p2=prev[l];
                temp[l]=p1+p2;
          }

        }

        prev=temp;
    }
   return prev[j];
}


// path having obstrical
/*  0 0 0
    0 -1 0
    0 0 0 
    
    -1 is obstrical */

int total_path_with_obstrical(vector<vector<int>> v,int i,int j){

   if(i==0&&j==0) return 1;
   
   int p1=0,p2=0;

   if(i-1>=0&&v[i-1][j]!=-1) p1 = total_path_with_obstrical(v,i-1,j);  

   // instead of using condition v[i-1][j]!=-1 we can also use if(v[i][j]==-1) return 0; as base case

   if(j-1>=0&&v[i][j-1]!=-1) p2 = total_path_with_obstrical(v,i,j-1);

  return p1+p2;

}

// using DP
int total_path_with_obstrical_1(vector<vector<int>> v,vector<vector<int>> dp,int i,int j){

   if(i==0&&j==0) return 1;
   
   int p1=0,p2=0;

   if(i-1>=0&&v[i-1][j]!=-1){ 
       if(dp[i-1][j]==-1) dp[i-1][j]= total_path_with_obstrical_1(v,dp,i-1,j);
       p1 = dp[i-1][j] ;
   }
   if(j-1>=0&&v[i][j-1]!=-1){ 
       if(dp[i][j-1]==-1) dp[i][j-1]=total_path_with_obstrical_1(v,dp,i,j-1);
       p2 = dp[i][j-1];
   }

  return p1+p2;

}


// space obtimization 
int total_path_with_obstrical(vector<vector<int>>v,int i,int j){
    vector<int> pre(j+1,0);
    for(int k=0;k<=i;k++){
        vector<int> temp(j+1,0);
            for(int l=0;l<=j;l++){
                if(k==0&&l==0) temp[l]=1;
                else if(v[k][l]==-1) temp[l]=0;
                else{
                    int p1=0,p2=0;
                    if(l>0) p1=temp[l-1];
                    if(k>0) p2=pre[l];
                    temp[l]=p1+p2;
                }
            }
            pre=temp;
    }
     return pre[j];  
}


int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<total_path1(n-1,m-1,dp);

    cout<<total_path(n-1,m-1)<<"  "<<total_path2(n-1,m-1);

    vector<vector<int>> v={{0,0,0},{0,-1,0},{0,0,0}};
    cout<<total_path_with_obstrical(v,n-1,m-1);

    vector<vector<int>> dp_1(n,vector<int>(m,-1));
    cout<<total_path_with_obstrical_1(v,dp_1,n-1,m-1);

    return 0;
}