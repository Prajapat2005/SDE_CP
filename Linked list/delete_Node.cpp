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

Node* delete_head(Node* head){

    Node*temp = head;
    head=head->next;
    free(temp);
    return head;
}

Node* delete_last(Node* head){

    Node*second_last = head;
    while(second_last->next->next!=NULL) second_last=second_last->next;
    Node*temp=second_last->next;
    second_last->next=NULL;
    free(temp);
    return head;
}

// we not include edge cases head node or last node
Node* delete_at_position(Node* head,int k){

    Node*pre=head;
    for(int i=1;i<k-1;i++){
        pre=pre->next;
    }
    Node*temp=pre->next;
    pre->next=pre->next->next;
    free(temp);
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

    head=delete_head(head);
    head=delete_last(head);
    temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    } 
}
