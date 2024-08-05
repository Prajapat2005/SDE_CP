#include <bits/stdc++.h>
using namespace std;

int min_coin(vector<int> v, int target , int index){
      
      if(index==0){
          if(target%v[0]==0) return target/v[0];  // {4,......} and T=12 then you take 3 coin of 4
          else return 1e9;                        // {5......} and T=12  then you can't achieve target
      }
      
      int Not_take = min_coin(v,target,index-1);
      
      int take=INT_MAX ;
      if(v[index]<=target){
          take = 1 + min_coin(v,target-v[index],index); 
          //infinite number of coin that's why index remain same but it will decrease by 1 in next recursion call
      }
      
      return min(Not_take ,take);
}

// tabulation as before done
// space obtimization as before done

// total no. ow ways to achieve target
int count(vector<int> v, int target , int index){
      
      if(index==0){
          if(target%v[0]==0) return 1;  
          else return 0;                       
      }
      
      int Not_take = count(v,target,index-1);
      
      int take=0 ;
      if(v[index]<=target){
          take = count(v,target-v[index],index); 
      }
      
      return Not_take+take;
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
         cin>>v[i];
    }
    cout<<min_coin(v,11,n-1);

    return 0;
}