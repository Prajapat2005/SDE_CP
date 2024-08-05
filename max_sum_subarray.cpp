/* when sum<0 then asign sum=0 
and store previous max sum 
when sum==0 we have new start of array when sum<0 end of sub array*/

#include <bits/stdc++.h>
using namespace std;
int ans(vector<int> v,int &ans_start,int &ans_end){
    int sum=0,max1=INT_MIN;
    int start;
    for(int i=0;i<v.size();i++){
        if(sum==0) start=i;
        sum=sum+v[i];
        if(sum>max1){ 
            max1=sum;
            ans_start=start;
            ans_end=i;
        }
        if(sum<0) sum=0;
    }
    return  max1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int x,y;
    cout<<ans(v,x,y)<<endl;
    for(int i=x;i<=y;i++) cout<<v[i]<<" ";
    return 0;
}