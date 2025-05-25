/* 10C4   (10/1)*(9/2)*(8/3)*(7/4)  
O(r) */

#include <bits/stdc++.h>
using namespace std;
long long nCr(int n,int r){
   long long ans=1;
    for(int i=1;i<=r;i++){
        ans=ans*(n-i+1);
        ans=ans/i;
    }
    return ans;
}
int main() {
    cout<<nCr(10,2);
    
    return 0;
}

/*pascal triangle 
row wise print concept in copy*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int p;
    cin>>p;
    for(int n=0;n<p;n++){
         int k=n;
         int ans=1;
         cout<<ans<<" ";
         for(int r=1;r<n;r++){
             ans=ans*(n-r+1);
             ans=ans/r;
             cout<<ans<<" ";
         }
         cout<<"\n";
    }
    return 0;
}