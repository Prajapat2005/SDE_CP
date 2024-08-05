#include <bits/stdc++.h>
using namespace std;
long long binary_search(vector<int> v,int k){
    long long l=0;
    long long h=v.size()-1;
    while(l<=h){
        long long mid = l + (h-l)/2;
        if(v[mid]<k){
            l = mid + 1;
        }
        else if(v[mid]>k){
            h = mid - 1;
        }
        else{
            return mid;
            
        }
    }
    return -1;
}

/*   lower bound   k<=v[i] 
     upper bound   k<v[i]      */
int upper_bound(vector<int> v,int k){ 
    int l=0;
    int h=v.size()-1;
    int u_bound=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(v[mid]<k){
            l=mid+1;
        }
        else if(v[mid]>k){
            h=mid-1;
            u_bound=mid;
        }
        else{
            u_bound=mid;
            break;
        }
    }
    return u_bound;
}

/* 6,7,8,9,1,2,3,4,5  if mid=(l+h)/2 than either left or right part of mid is sorted or both sorted
then find that part then move pointer accordingly */
int binary_search_in_rotated_array(vector<int> v,int k){
    int l=0;
    int h=v.size()-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(v[mid]==k) return mid;
        if(v[mid]==v[l]&&v[mid]==v[h]){ // for the case {6,6,7,8,9,1,2,3,4,6} because sort compare is not valid in this case
            l++;
            h--;
            continue;
        }
        if(v[l]<=v[mid]){   //left sorted
             if(v[l]<=k&&k<v[mid]) h=mid-1;  // if k lies in between sorted array
             else l=mid+1;
        }
        else{               // right sorted
             if(v[h]>=k&&k>v[mid]) l=mid+1;  // if k lies in between sorted array
             else h=mid-1;
        }    
    }
    return -1;
}

// find min in rotated array min of sorted side
int find_min(vector<int> v){  
    int l=0;
    int h=v.size()-1;
    while(l<=h){
        int mid=(l+h)/2;
        int ans=INT_MAX;
        if(v[mid]==v[l]&&v[mid]==v[h]){ // for the case {6,6,7,8,9,1,2,3,4,6} because sort compare is not valid in this case
            l++;
            h--;
            continue;
        }
        if(v[l]<=v[mid]){   //left sorted
            ans=min(v[l],ans);
            l=mid+1;         // mive to right side because we take min of left
        }
        else{               // right sorted
             ans=min(v[mid],v[ans]);
             h=mid-1;       // mive to left side because we take min of right
        }    
    }
    return -1;
}

/* {1,1,2,2,3,3,4,5,5,6,6,7,7}    before single element same element are in first even then odd
                                   after single element same element are in first odd then even*/
int find_single(vector<int> v){
    int l=0;
    int h=v.size()-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(v[mid]!=v[mid+1]&&v[mid]!=v[mid-1]) return v[mid];
        if(mid%2==0){
            if(v[mid]==v[mid+1]) l=mid+2; // e o combination
            else h=mid-2;                 // o e combination
        }
        else{
            if(v[mid]==v[mid-1]) l=mid+2;  // e o combination
            else h=mid-2;                  // o e combination
        }
    }
    return -1;
}

int main() {
    vector<int> v={1,3,4,5,6,7,8,9,10};
    cout<<binary_search(v,2);
    return 0;
}