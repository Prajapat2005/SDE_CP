#include <bits/stdc++.h>
using namespace std;
bool ans(vector<int>v,int x,int &k,int &j){
    int n=v.size();
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int more=x-v[i];
        if(mp.find(more)!=mp.end()){
            k=i;
            j=mp[more];
            return true;
        }  
        else mp[v[i]]=i;
    }
    return false;
}
int main() {
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int i,j;
    cout<<ans(v,x,i,j);
    cout<<"\n"<<i<<" "<<j;
    return 0;
}