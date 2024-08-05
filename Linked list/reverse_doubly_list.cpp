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

void reverse_Doubly(Doubly_Node* head_1){
     
    Doubly_Node* temp=head_1;
    stack<int> s;
    while(temp!=NULL){
        s.push(temp->value);
        temp=temp->front;
    }
    temp=head_1; 
    while(!s.empty()){
        temp->value=s.top();
        temp=temp->front;
        s.pop();
    }
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
     reverse_Doubly(head_1);
     Doubly_Node* temp=head_1;
     while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->front;
     }

}
