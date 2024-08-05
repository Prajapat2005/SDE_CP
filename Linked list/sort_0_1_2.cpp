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

Node* sort_0_1_2(Node* head){

      Node*one_head=new Node(-1);
      Node*two_head=new Node(-1);
      Node*zero_head=new Node(-1);
      Node*one=one_head;
      Node*two=two_head;
      Node*zero=zero_head;

      Node*temp=head;
      while(temp){
         if(temp->valur==0){ zero->next=temp;  zero=zero->next}
         else if(temp->valur==1){ one->next=temp;  one=one->next}
         else{ two->next=temp;  two=two->next}
         temp=temp->next;
      }
      one_head=one_head->next;
      zero_head=zero_head->next;
      two_head=two_head->next; 
      if(one_head!=NULL) zero->next=one_head;
      if(two_head!=NULL) one->next=two_head;  
      // code remain to joint

}

int main(){

   Node* head1 = new Node(2);
   head1->next = new Node(3);
   cout<<head1->value<<" "<<head1->next->value<<"\n";
   cout<<head1->next;
   
    vector<int> v={1,0,1,2,0,2,1};
    Node* head = new Node(v[0]);
    Node*temp = head;
    for(int i=1;i<v.size();i++){
        temp->next=new Node(v[i]);
        temp=temp->next;
    }
    sort_0_1_2(head);
    temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    } 
}
