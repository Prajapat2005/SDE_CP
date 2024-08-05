#include <bits/stdc++.h>
using namespace std;
/* do all possible ways and find min */
int frog_jump(vector<int> v,int index){
    if(index==0) return 0;
    if(index==1){
        return abs(v[1]-v[0]);
    }
    int p1=abs(v[index]-v[index-1])+frog_jump(v,index-1);    // ans(v,index-1) is cost to reach i-1 index
    int p2=abs(v[index]-v[index-2])+frog_jump(v,index-2);    // ans(v,index-2) is cost to reach i-2 index
    return min(p1,p2);      // find min of both condition
}

// using DP
int ans1(vector<int> v,int index,vector<int> &dp){
    if(index==0) return 0;

    if(index==1){
        return abs(v[1]-v[0]);
    }

    if(dp[index-1]==-1) dp[index-1]=ans1(v,index-1,dp);
    int p1=abs(v[index]-v[index-1])+dp[index-1];
    
    if(dp[index-2]==-1) dp[index-2]=ans1(v,index-2,dp);
    int p2=abs(v[index]-v[index-2])+dp[index-2];

    return min(p1,p2);
}

// without using extra space
int ans2(vector<int> v,int index){
    int pre1=abs(v[0]-v[1]);
    int pre2=0;
    int current;
    for(int i=2;i<=index;i++){
        int p1=abs(v[i]-v[i-1])+pre1;
        int p2=abs(v[i]-v[i-2])+pre2;
        current=min(p1,p2);
        pre2=pre1;
        pre1=current;
    }
    return current;
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<frog_jump(v,v.size()-1); 

    vector<int> v(n),dp(n+1,-1);
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    cout<<ans1(v,v.size()-1,dp);
    return 0;
}