#include<iostream>
using namespace std;
int const N=1e3;
void insertheapMIN(int a[], int &size,int k){
    size++;
    a[size]=k;
    int curr=size;
    while(curr/2>0 && a[curr]<a[curr/2]){
        swap(a[curr],a[curr/2]);
        curr=curr/2;
    }
}
void insertheapMAX(int a[], int &size,int k){
    size++;
    a[size]=k;
    int curr=size;
    while(curr/2>0 && a[curr]>a[curr/2]){
        swap(a[curr],a[curr/2]);
        curr=curr/2;
    }
}
int main(){
    int minheap[N]={-1,10,20,30,40,50};
    int size=5;
    insertheapMIN(minheap,size,5);
    for(int t=0;t<=size;t++){
        cout<<minheap[t]<<" ";
    }
    int maxheap[N]={-1,60,50,40,30,20,10};
    int size=6;
    insertheapMAX(maxheap,size,5);
    for(int t=0;t<=size;t++){
        cout<<minheap[t]<<" ";
    }
    return 0;
}
/* min heap {10,20,30,40,50}
             10
         20      30
       40  50 
       after insertion 5
      { 5 20 10 40 50 30 }
               5
           20     10
         40  50  30     */
/*  max heap {60,50,40,30,20,10}
             60
         50      40
       30  20  30
       after inserting 5
      {100 50 60 30 20 10 40 }
              100
          50       60
        30  20    10  40      */         