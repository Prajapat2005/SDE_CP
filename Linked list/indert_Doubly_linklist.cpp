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

void insert_head(Doubly_Node* &head_1,int n){

     Doubly_Node* new_node = new Doubly_Node(n);
     head_1->back=new_node;
     new_node->front=head_1;
     head_1=head_1->back;


}

void insert_last(Doubly_Node* &head_2,int n){

     Doubly_Node* new_node = new Doubly_Node(n);
     head_2->front=new_node;
     new_node->back=head_2;
     head_2=head_2->front;
    

}

// we not include edge cases head node or last node
Doubly_Node* insert_at_position(Doubly_Node* &head_1, int k,int n){

    Doubly_Node* new_node=new Doubly_Node(n);
    Doubly_Node* temp1=head_1;
    for(int i=1;i<k-1;i++){
        temp1=temp1->front;
    }
    new_node->front=temp1->front;
    temp1->front=new_node;
    new_node->back=temp1;
    temp1=temp1->front->front;
    temp1->back=new_node;

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

   // insert_head(head_1,0);
   // insert_last(head_2,8);
    insert_at_position(head_1,3,-1);

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
