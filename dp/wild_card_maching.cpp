#include <bits/stdc++.h>
using namespace std;
int ans(string s1,string s2,int i,int j){
    if(i<0&&j<0) return true;
    if(i<0&&j>=0) return false;
    if(j<0&&i>=0){
        for(int k=0;k<=i;k++){
            if(s1[k]!='*') return false;
        }
        return true;
    }
    
    if(s1[i]==s2[j]||s1[i]=='?') return ans(s1,s2,i-1,j-1);
    if(s1[i]=='*'){
        return ans(s1,s2,i-1,j)||ans(s1,s2,i,j-1);
    }
    if(s1[i]!=s2[j])
    return false;
}

// all other function can also be make as done as before
int main() {
    string s1="ab*cd";
    string s2="abdefcd";
    cout<<ans(s1,s2,4,6);
    return 0;
}