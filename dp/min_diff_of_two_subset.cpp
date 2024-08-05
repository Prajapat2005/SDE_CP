#include <bits/stdc++.h>
using namespace std;


void target_sum(vector<int> v,vector<vector<int>> &dp,int target , int index){
    for(int i=0;i<=index;i++) dp[i][0]=true;
    for(int i=0;i<=target;i++){
        if(i==v[0]) dp[0][i]=true;
        else dp[0][i]=false;
    }
     
    for(int i=1;i<=index;i++){
        for(int j=1;j<=target;j++){
           bool Not_take = dp[i-1][j];
           bool take = false;
           if(v[i]<=j){
               take = dp[i-1][j-v[i]];
           }
           dp[i][j] = take||Not_take;
        }
    }
}


//space obtimization
vector<int> target_sum_1(vector<int> v,int target , int index){

    vector<int> prev(target+1,0),curr(target+1,0);
    prev[0]=true; curr[0]=true;
    prev[v[0]]=true;

    for(int i=1;i<=index;i++){
        for(int j=1;j<=target;j++){
           bool Not_take = prev[j];
           bool take = false;
           if(v[i]<=j){
               take = prev[j-v[i]];
           }
           curr[j] = take||Not_take;
        }
        prev=curr;
    }
    return prev;
}


int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int sum=0;
    for(int i=0;i<n;i++){ 
        cin>>v[i];
        sum=sum+v[i];
    }
    
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    target_sum(v,dp,sum,n-1);

    if(dp[n-1][sum/2]==1) cout<<0;
    else{
        int ans1;
        for(int i=sum/2;i<=sum;i++){
            if(dp[n-1][i]==1){
                cout<<2*i-sum;
            }
        }
         
    }

    vector<int>dp_1=target_sum_1(v,sum,n-1);

    if(dp_1[sum/2]==1) cout<<0;
    else{
        int ans1,ans2;
        for(int i=sum/2;i<=sum;i++){
            if(dp_1[i]==1){
                cout<<2*i-sum;
            }
        }
         
    }
    return 0;
}