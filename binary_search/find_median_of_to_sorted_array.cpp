#include<bits/stdc++.h>
using namespace std;

int median1(vector<int>v1,vector<int>v2){

    int l=0;         // range of count of element should be on left from median when array is sorted
    int r=v1.size(); 
    int x=(v1.size()+v2.size()+1)/2; // element left and right of median
    int l1,r1,l2,r2;

    while(l<=r){
        int mid=(r-l)/2 + l;

        if(mid-1<0) l1=INT_MIN;             // mid1 count of element of v1 on left
        else l1=v1[mid-1];

        if(mid>=v1.size())  r1=INT_MAX;      
        else r1=v1[mid];                    // mid1+mid2 == x

        if(x-mid-1<0)  l2=INT_MIN; 
        else l2=v2[x-mid-1];                //v2[mid2-1] 

        if(x-mid>=v2.size()) r2=INT_MAX;          
        else  r2=v2[x-mid];                   // mid2 count of element of v2 on left

        if(l1>r2){
            r=mid-1; // left count decrease of array 1
        }
        else if(l2>r1){
            l=mid+1;   // left count increse of array 1
        }
        else{
            break;
        }

    }
    if((v1.size()+v2.size())%2==0)
    return(max(l1,l2)+min(r1,r2))/2;

    else 
    return max(l1,l2);


}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v1(n),v2(m);

    for(int i=0;i<n;i++) cin>>v1[i];
    for(int i=0;i<m;i++) cin>>v2[i];
    
    if(v1.size()<v2.size())   // decrease number of test case
    cout<<median1(v1,v2);

    else{
        cout<<median1(v2,v1);
    }

}