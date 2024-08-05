#include<bits/stdc++.h>
using namespace std;

int longest_divisible_subset(vector<int> v, int ind, int prev_ind){

    if(ind==v.size()) return 0;

    if(prev_ind==-1 || v[ind]%v[prev_ind]==0){
        int take = 1 + longest_divisible_subset(v,ind+1,ind);
        int not_take = 0 + longest_divisible_subset(v,ind+1,prev_ind);
        return max(take , not_take);
    }
    else return longest_divisible_subset(v,ind+1,prev_ind);

}

// all 3 function same as largest increasing subsequence


// longest string chain
bool compare(string s1,string s2){
    if(s1.length()!=s2.length()+1) return false;
    else{
         
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int count=0;
        int i=0,j=0;
        while(i<s1.length()){
            
            if(s1[i]!=s2[j]){
                count++;
                s1.erase(s1.begin()+i);
            }
            else{ i++;  j++; }

        }

        if(count==1) return true;
        else return false;

    }
}

int longest_string_chain(vector<string> v, int ind, int prev_ind){

    if(ind==v.size()) return 0;

    if( prev_ind==-1 || compare(v[ind],v[prev_ind]) ){
        int take = 1 + longest_string_chain(v,ind+1,ind);
        int not_take = 0 + longest_string_chain(v,ind+1,prev_ind);
        return max(take , not_take);
    }
    else return longest_string_chain(v,ind+1,prev_ind);

}


// longest bitonic subsequence




int main(){
    
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    cout<<longest_string_chain(v,0,-1);
}