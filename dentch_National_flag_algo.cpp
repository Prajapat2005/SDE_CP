/*sorting of array containing 0/1/2
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int i=0;
    int mid , high , low;
    while(v[i]==0) i++; 
    low=i;
    if(v[i-1]==0&&v[i]==1){
        while(v[i]==1) i++;
    }
    mid=i;
    i=n-1;
    while(v[i]==2) i--;
    high=i;
    
    while(mid<=high){
        if(v[mid]==0){
            swap(v[low],v[mid]);
            low++;
            mid++;
        }
        else if(v[mid]==1) mid++;
        else{
            swap(v[mid],v[high]);
            high--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}