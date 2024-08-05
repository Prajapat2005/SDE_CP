/* 
 first find index after which array is strictly decreasing 
 then find smallest grater than value with respect to that index afer that then swap the number s
 {2,1,5,4,3,0,0}
 after index 1
 then swap index 1 and 4 {2,3,5,4,1,0,0}
 after tha sort i to end or reverse from i to end
 {2,3,0,0,1,4,5} -> ans
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int i=n-1;
    while(v[i]<=v[i-1]) i--;
    int min1=i;
    for(int k=i;k<n;k++){
        if(v[k]>v[i-1]){
            if(v[k]<v[min1]) min1=k;
        }
    }
    swap(v[min1],v[i-1]);
    for(int k=0;k<n;k++) cout<<v[k]<<" ";
    return 0;
}