#include <iostream>
using namespace std;
void get(int n, char a, char b,char c){
    if(n==0) return;
    get(n-1,a,b,c);
    cout<<a<<" "<<c<<endl;
    get(n-1,b,c,a);
}
int main() {
    int n;
    cin>>n;
    get(n,'1','2','3');

    return 0;
}