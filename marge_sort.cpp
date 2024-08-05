#include <bits/stdc++.h>
using namespace std;
void marge(vector<int> arr, int l, int mid, int r){
     int an=mid-l+1;
     int bn=r-mid;
     int a[an],b[bn];
     for(int i=0;i<an;i++) a[i]=arr[l+i];
     for(int i=0;i<an;i++) b[i]=arr[mid+1+i];
     int i=0,j=0,k=l;
     while(i<an&&j<bn){
         if(a[i]<b[j]) arr[k++]=a[i++];
         else { 
             arr[k++]=b[j++]; 
        } 
     }
     while(i<an) arr[k++]=a[i++];
     while(j<an) arr[k++]=b[j++];
}
void marge_sort(vector<int> arr,int l, int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    marge_sort(arr,l,mid);
    marge_sort(arr,mid+1,r);
    marge(arr,l,mid,r);
}

int main() {
    vector<int> v={5,3,2,4,1};
    marge_sort(v,0,4);
    return 0;
}