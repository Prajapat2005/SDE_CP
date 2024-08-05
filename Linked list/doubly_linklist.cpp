#include<bits/stdc++.h>
using namespace std;

class Doubly_Node{
public:
        int value;
        Doubly_Node* back;
        Doubly_Node* front;
    Doubly_Node(int x){
        value = x;
        back = NULL;
        front = NULL;
    }    
};

int main(){
/*
   Node* head1 = new Node(2);
   head1->next = new Node(3);
   cout<<head1->value<<" "<<head1->next->value<<"\n";
   cout<<head1->next;
   */
   
    vector<int> v={1,2,3,4,5,6,7};
    Doubly_Node* head = new Doubly_Node(v[0]);
    Doubly_Node* curr = head;
    for(int i=1;i<v.size();i++){
        curr->front = new Doubly_Node(v[i]);
        Doubly_Node* New_Node = curr->front;
        New_Node->back=curr;
        curr=curr->front;
    }

   // head=delete_head(head);
 //   head=insert_head(head,0);
 //   head=insert_last(head,8);
 //   head=insert_at_position(head,5,-1);
    Doubly_Node*temp = head;
    Doubly_Node*head_2 = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->front;
        if(head_2->front!=NULL) head_2=head_2->front;  // head_2 at last node
    }
    cout<<"\n";
    Doubly_Node* temp1=head_2;
    while(temp1!=NULL){
        cout<<temp1->value<<" ";
        temp1 = temp1->back;
    }

}
