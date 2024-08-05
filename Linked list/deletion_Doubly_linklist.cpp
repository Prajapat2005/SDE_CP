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

Doubly_Node* delete_head(Doubly_Node* head_1){

     Doubly_Node* temp=head_1;
     head_1=head_1->front;
     head_1->back=NULL;
     free(temp);

     return head_1;

}

Doubly_Node* delete_last(Doubly_Node* head_2){

     Doubly_Node* temp=head_2;
     head_2=head_2->back;
     head_2->front=NULL;
     free(temp);

     return head_2;

}

// we not include edge cases head node or last node
Doubly_Node* delete_at_position(Doubly_Node* head_1, int k){

    Doubly_Node* temp1=head_1;
    for(int i=1;i<k-1;i++){
        temp1=temp1->front;
    }
    Doubly_Node* temp2=temp1->front;

    temp1->front=temp1->front->front;
    temp1=temp1->front;
    temp1->back=temp1->back->back;
    free(temp2);
    return head_1;

}

int main(){
/*
   Node* head1 = new Node(2);
   head1->next = new Node(3);
   cout<<head1->value<<" "<<head1->next->value<<"\n";
   cout<<head1->next;
   */
   
    vector<int> v={1,2,3,4,5,6,7};
    Doubly_Node* head_1 = new Doubly_Node(v[0]);   // front head
    Doubly_Node* curr = head_1;
    for(int i=1;i<v.size();i++){
        curr->front = new Doubly_Node(v[i]);
        Doubly_Node* New_Node = curr->front;
        New_Node->back=curr;
        curr=curr->front;
    }
    Doubly_Node* head_2=curr;   // last head
 //   head_1=delete_head(head_1);
 //   head_2=delete_last(head_2);
      head_1=delete_at_position(head_1,4);
 //   head=insert_head(head,0);
 //   head=insert_last(head,8);
 //   head=insert_at_position(head,5,-1);
    Doubly_Node*temp = head_1;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->front;
    }
    cout<<"\n";
    Doubly_Node* temp1=head_2;
    while(temp1!=NULL){
        cout<<temp1->value<<" ";
        temp1 = temp1->back;
    }

}
