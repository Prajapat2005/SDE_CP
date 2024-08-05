//https://codeforces.com/problemset/problem/1506/C problem

#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int match(string a, string b, int i){
    int k=i;
    int count=0;
    for(;k<i+b.length();k++){
        int count1=0;
        if(a[k]==b[k-i]){
            while(a[k]==b[k-i]&&k<a.length()){
                count1++;
                k++;
            }
            count=max(count,count1);
        }
    }
    return count;
}
int compare2(string a,string b,int i){
    int k=b.length()-i-1;
    int p=0;
    int count=0;
    for(;k<b.length();k++){
        int count1=0;
        if(a[p]==b[k]){
            while(a[p]==b[k]&&k<b.length()){
                count1++;
                k++;
                p++;
            }
            count=max(count,count1);
        }
        p++;
    }
    return count;
}
int compare3(string a,string b,int i){
    int k=i;
    int p=0;
    int count=0;
    for(;k<a.length();k++){
        int count1=0;
        if(b[p]==a[k]){
            while(b[p]==a[k]&&k<a.length()){
                count1++;
                k++;
                p++;
            }
            count=max(count,count1);
        }
        p++;
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int count=0;
        if(a.length()<b.length()) swap(a,b);
        for(int i=0;i<=a.length()-b.length();i++){
            count=max(count,match(a,b,i));
        }
        for(int i=0;i<b.length()-1;i++){
            count=max(compare2(a,b,i),count);
        }
        for(int i=a.length()-b.length()+1;i<a.length();i++){
           count=max(count,compare3(a,b,i));
        }
        cout<<a.length()+b.length()-2*count<<endl;
    }
    return 0;
}