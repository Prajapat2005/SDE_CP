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

Node* insert_head(Node* head,int n){

    Node*temp = new Node(n);
    temp->next=head;
    head = temp;
    return head;

}

Node* insert_last(Node* head,int n){

    Node* last = head;
    while(last->next!=NULL) last=last->next;
    last->next=new Node(n);
    return head;

}

// we not include edge cases head node or last node
Node* insert_at_position(Node* head,int k,int n){

    Node*pre=head;
    for(int i=1;i<k-1;i++){
        pre=pre->next;
    }
    Node* temp=pre->next;
    pre->next=new Node(n);
    pre->next->next=temp;
    return head;

}

int main(){
/*
   Node* head1 = new Node(2);
   head1->next = new Node(3);
   cout<<head1->value<<" "<<head1->next->value<<"\n";
   cout<<head1->next;
   */
   
    vector<int> v={1,2,3,4,5,6,7};
    Node* head = new Node(v[0]);
    Node*temp = head;
    for(int i=1;i<v.size();i++){
        temp->next=new Node(v[i]);
        temp=temp->next;
    }

   // head=delete_head(head);
    head=insert_head(head,0);
    head=insert_last(head,8);
    head=insert_at_position(head,5,-1);
    temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    } 
}
