#include<iostream>
using namespace std;
int const N=1e3;
void deleteheapMIN(int a[],int &size,int k){
    int curr=0;
    while(a[curr]!=k){
        curr++;
    }
    swap(a[curr],a[size]);
    size--;
    while(curr*2 <= size){
        int leftchild = curr*2;
        int rightchild = curr*2+1;
        int minchild= leftchild;
        if(rightchild<=size && a[rightchild]<a[minchild]){
            minchild = rightchild;
        }
        if(a[minchild]>a[curr]){
            return;
        }
        swap(a[minchild],a[curr]);
        curr = minchild;
    }
}  
void deleteheapMAX(int a[],int &size,int k){
    int curr=0;
    while(a[curr]!=k){
        curr++;
    }
    swap(a[curr],a[size]);
    size--;
    while(curr*2 <= size){
        int leftchild = curr*2;
        int rightchild = curr*2+1;
        int minchild= leftchild;
        if(rightchild<=size && a[rightchild]>a[minchild]){
            minchild = rightchild;
        }
        if(a[minchild]<a[curr]){
            return;
        }
        swap(a[minchild],a[curr]);
        curr = minchild;
    }
} 
int main(){
    int minheap[N]={-1,10,20,30,40,50,60,70};
    int size=7;
    deleteheapMIN(minheap,size,5);
    for(int t=0;t<=size;t++){
        cout<<minheap[t]<<" ";
    }
    int maxheap[N]={-1,70,60,50,40,30,20,10};
    size=7;
    deleteheapMAX(maxheap,size,40);
    for(int t=0;t<=size;t++){
        cout<<minheap[t]<<" ";
    }
    return 0;
}
/* min heap { 10 20 30 40 50 60 70}
             10
         20      30
       40  50  60  70
       delete 50
      { 10 20 30 40 70 60 }
             10
          20     30
        40  70  60      
    max heap { 70 60 50 40 30 20 10}
             70
        60        50    
      40  30   20   10      
      delete 40
      {70 60 50 10 30 20 }
             70
         60      50
       10  30  20     */
