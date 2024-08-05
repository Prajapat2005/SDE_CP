#include <iostream> 
#include<vector>
using namespace std;
bool sieve(int n){
    vector<int> v(n+1,1);
    v[0]=v[1]=0;
    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j=j+i){
            v[j]=0;
        }
    }
    if(v[n]==1) return true;
    else return false;
}

int main() {
    cout<<sieve(12);
    return 0;
}