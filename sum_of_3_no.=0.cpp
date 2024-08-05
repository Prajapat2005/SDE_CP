/* v[i]+v[j]+v[k]=0    
v[k]=-(v[i]+v[j]) 
and k in between i and j pointer
after j pointer move forward v[j] insert in set;
after every i pointer new set create
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int count=0;
    for(int i=0;i<n-1;i++){
        set<int> s;
        for(int j=i+1;j<n;j++){
           int k=-(v[i]+v[j]);
           if(s.find(k)!=s.end()) count++;
           s.insert(v[j]);
        }
    }
    cout<<count;
    return 0;
}
/* using 3 pointers i is fix and j and k moving */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int count=0;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
         int j=i+1;
         int k=n-1;
         while(j<k){
             int sum=v[i]+v[j]+v[k];
             if(sum<0) j++;
             else if(sum>0) k--;
             else{
                 count++;
                 j++;
                 k--;
                 while(j<k&&v[j]==v[j-1]) j++;
                 while(j<k&&v[k]==v[k+1]) k--;
             }
         }
    }
    cout<<count;
    return 0;
}