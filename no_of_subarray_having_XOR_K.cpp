#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,int> mp;
    mp[0]=1;
    int xr=0;
    int count=0;
    for(int i=0;i<n;i++){
        xr=xr^v[i];
        int x=xr^k;
        if(mp.find(x)!=mp.end()) count=count+mp[x];
        mp[xr]++;
    }
    cout<<count;
    return 0;
}