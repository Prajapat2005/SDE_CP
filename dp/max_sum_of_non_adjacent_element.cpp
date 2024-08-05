#include <bits/stdc++.h>
using namespace std;

/*   same concept as frog jump problem
       start from last and try to find max sum in all possible ways
*/ 
int max_sum(vector<int> v,int index){
    if(index==0) return v[0];

    if(index==1) return v[1];
     
    if(index==2) return v[2]+v[0];

    int p1,p2;
    p1=v[index]+max_sum(v,index-2);
    p2=v[index]+max_sum(v,index-3);

    return max(p1,p2);
    
}

// using DP  dp[0]=v[0]  dp[1]=v[1]  dp[2]=v[2]+v[0]
int max_sum1(vector<int> v , int index , vector<int> &dp){
    if(index==0) return v[0];

    if(index==1)  return v[1];

    if(index==2)  return v[2]+v[0];

    if(dp[index-2]==-1) dp[index-2]=max_sum1(v,index-2,dp);
    int p1=v[index] + dp[index-2];
    
    if(dp[index-3]==-1) dp[index-3]=max_sum1(v,index-3,dp);
    int p2=v[index] + dp[index-3];

    return max(p1,p2);
}

// without using extra space
int max_sum2(vector<int> v,int index){
   int pre1=v[0]+v[2];
   int pre2=v[1];
   int pre3=v[0];
   for(int i=3;i<=index;i++){
       int p1=v[i]+pre2;
       int p2=v[i]+pre3;
       int curr=max(p1,p2);
       pre3=pre2;
       pre2=pre1;
       pre1=curr;
    }
    return pre1;
}


int main() {
    int n;
    cin>>n;
    vector<int> v(n),dp(n+1,-1);
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<max(max_sum(v,v.size()-1),max_sum(v,v.size()-2));  

    /*max(when we take last , when we take second last) because both togather are not 
    possible and max sum can be from last or from second last element  */

    return 0;
}