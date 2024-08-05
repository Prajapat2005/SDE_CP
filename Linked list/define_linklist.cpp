#include<bits/stdc++.h>
using namespace std;

class Node{
public:
        int value;
        Node* next;
    Node(int x){
        value = x;
        next = NULL;
    }
    Node(int x,Node* next1){
        value = x;
        next = next1;
    }    
};

int main(){

   Node* head1 = new Node(2);
   head1->next = new Node(3);
   cout<<head1->value<<" "<<head1->next->value<<"\n";
   cout<<head1->next;
   
    vector<int> v={1,2,3,4,5,6,7};
    Node* head = new Node(v[0]);
    Node*temp = head;
    for(int i=1;i<v.size();i++){
        temp->next=new Node(v[i]);
        temp=temp->next;
    }
    temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    } 
}
