#include<iostream>
using namespace std;
int const N=1e3;
void heapifyMIN(int a[],int &size,int curr){
    while(curr*2<=size){
        int leftchild=curr*2;
        int rightchild=curr*2+1;
        int minchild= leftchild;
        if(rightchild<=size && a[rightchild]<a[minchild]){
            minchild = rightchild;
        }
        if(a[minchild]>=a[curr]){
            return;
        }
        swap(a[curr],a[minchild]);
        curr=minchild;
    }
}
void heapifyMAX(int a[],int &size,int curr){
    while(curr*2<=size){
        int leftchild=curr*2;
        int rightchild=curr*2+1;
        int maxchild= leftchild;
        if(rightchild<=size && a[rightchild]>a[maxchild]){
            maxchild = rightchild;
        }
        if(a[maxchild]<=a[curr]){
            return;
        }
        swap(a[curr],a[maxchild]);
        curr=maxchild;
    }
}
int main(){
    int minheap[N]={-1,50,30,20,40,70,60,10};
    int size=7;
    for(int i=size/2;i>0;i--){
        // i-> parent node parent note started from size/2
        heapifyMIN(minheap,size,i);
    }
    for(int i=1;i<=size;i++){
        cout<<minheap[i]<<" ";
    }   
    for(int i=size/2;i>0;i--){
        // i-> parent node parent note started from size/2
        heapifyMAX(minheap,size,i);
    }
    for(int i=1;i<=size;i++){
        cout<<minheap[i]<<" ";
    } 
    return 0;
}
/* 10 30 20 40 70 60 50 
    min heap
           10
       30      20
     40  70  60  50 
    max heap
    70 50 60 40 30 20 10
           70
       50      60
     40  30  20  10    
         
     */ 