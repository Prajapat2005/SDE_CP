#include<iostream>
#include<vector>
class node{
    public :
       int value;
       node* next;
     node(int x){
         value=x;
         next=NULL;
     }  
};
void insertathead(node* &head, int value){
    node *new_node = new node(value);
    new_node-> next = head;
    new_node=head;
    }
void insertatend(node* &head, int value){
    node* new_node = new node(value);
    node* temp =head;
    while(temp->next != NULL){
        temp= temp->next;
    }
    temp= temp-> next;
    temp->next= new_node;
    new_node = NULL;
}
void insert(node* &head, int value, int k){
    node* new_node= new node(value);
    node* temp1;
    for(int i=0; i<k-1 ; i++){
        temp1= temp1->next;
    }
    new_node->next=temp1->next;
    temp1->next=new_node;
}
void deleteathead(node* &head){
    node* temp=head;
    head=head->next;
    free(temp);
}
void deleteatend(node* &head){
    node* temp=head;
    node* temp1;
    while(temp->next!= NULL){
        temp=temp->next;
    }
    temp1=temp->next;
}
int main(){
    node* x = new node(2);
    return 0;
}