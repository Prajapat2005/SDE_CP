#include<bits/stdc++.h>
using namespace std;
int fibonacci1(int n,vector<int> &dp){
    if(n==0||n==1) return n;
    if(dp[n]==0) dp[n]=fibonacci1(n-1,dp)+fibonacci1(n-2,dp);
    return dp[n];
}

/*without using extra space bottom up approch Base case to result */
int fibonacci2(int n){
    int pre2=0;
    int pre1=1;
    int curr;
    for(int i=2;i<=n;i++){
       curr = pre1 + pre2 ;
       pre2=pre1;
       pre1=curr;
    }
    return curr;
}
  
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[1]==1;
    int k = fibonacci1(n,dp);
    cout<<k;
}