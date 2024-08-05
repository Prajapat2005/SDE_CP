#include <bits/stdc++.h>
using namespace std;
int ans(string s1,string s2,int i1, int i2){
    
    if(i2<0) return 1;  // whole S2 match and pointer decrease to -1
    if(i1<0) return 0;  
    // whole s1 is not match and pointer decrease to -1 
    //but in case of f(-1,-1) recursion return 1 because i2 condition we written first
    
    if(s1[i1]==s2[i2]) return ans(s1,s2,i1-1,i2)+ans(s1,s2,i1-1,i2-1);   // Not take and Take case
    
    if(s1[i1]!=s2[i2]) return ans(s1,s2,i1-1,i2);    //if not equal then i2 to find match remain their and i1 decrease
    
}

// avoid overlaping
// dp of i is i-1 of stirng -1 based indexing
int ans_dp(string s1,string s2,vector<vector<int>> &dp,int i1, int i2){
    
    if(i2<0) return 1;  // whole S2 match and pointer decrease to -1
    if(i1<0) return 0;  
    // whole s1 is not match and pointer decrease to -1 
    //but in case of f(-1,-1) recursion return 1 because i2 condition we written first
    
    if(s1[i1]==s2[i2]){ 
        if(dp[i1][i2+1]==-1) dp[i1][i2+1] = ans_dp(s1,s2,dp,i1-1,i2);
        if(dp[i1][i2]==-1) dp[i1][i2] = ans_dp(s1,s2,dp,i1-1,i2-1);
        return dp[i1][i2+1]+dp[i1][i2];
        }   // Not take and Take case
    
    if(s1[i1]!=s2[i2]){ 
        if(dp[i1][i2+1]==-1) dp[i1][i2+1]=ans_dp(s1,s2,dp,i1-1,i2);
        return dp[i1][i2+1];   //if not equal then i2 to find match remain their and i1 decrease
        
        }    
    
}

// tabulation consider i of dp means i-1 of string
int ans_dp_2(string s1,string s2,vector<vector<int>> &dp,int i1, int i2){
    
    for(int i=0;i<=s1.length();i++) dp[0][i]=0 // I1==-1 return 0;
    for(int i=0;i<=s2.length();i++) dp[i][0]=1 // I2==-1 return 1;

    dp[0][0]=1; // f(-1,-1)=1;

    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
             
             if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
             else{
                dp[i][j]=dp[i-1][j];
             }

        }
    }
    return dp[s1.length()][s2.length()];
}


int ans_dp_2(string s1,string s2,vector<vector<int>> &dp,int i1, int i2){
    
    vector<int> prev(s2.length()+1,0);   // I1==-1 return 0 
    vector<int> curr(s2.length()+1,0);

    prev[0]=1; curr[0]=1;  //f(-1,-1)=1

    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
             
             if(s1[i-1]==s2[j-1]) curr[j]= prev[j-1] +prev[j];
             else{                         //take      //not take
                curr[j]=prev[j];
             }            //not take;

        }
        prev=curr;
    }
    return prev[s2.length()];
}

 int main() {
    string s1="babgbag",s2="bag";
    cout<<ans(s1,s2,s1.size()-1,s2.size()-1);
    
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    cout<<ans_dp(s1,s2,dp,s1.size()-1,s2.size()-1);

    cout<<ans_dp_2(s1,s2,dp,s1.size()-1,s2.size()-1);
    return 0;
}