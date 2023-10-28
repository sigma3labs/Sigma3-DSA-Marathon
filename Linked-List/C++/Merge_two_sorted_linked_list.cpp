#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next = NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head == NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
}
node* solve(node* first, node* second){
    //only one element is present
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    
    node* curr1 = first;
    node* next1 = curr1->next;
    node* curr2 = second;
    node* next2 = curr2->next;
    
    while(next1!=NULL && curr2!=NULL){
        if((curr2->data >=curr1->data) && (curr2->data <= next1->data)){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
node* merge(node* &head1 , node* &head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    if(head1->data < head2->data){
        return solve(head1,head2);
    }
    else{
        return solve(head2,head1);
    }
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head = NULL;
    cout<<"First Linked List :"<<endl;
    insertAtTail(head,1);
    insertAtTail(head,3);
    insertAtTail(head,6);
    insertAtTail(head,9);
    insertAtTail(head,11);
    insertAtTail(head,12);
    display(head);
    cout<<"Second Linked List :"<<endl;
    node* head2 = NULL;
    insertAtTail(head2,2);
    insertAtTail(head2,4);
    insertAtTail(head2,5);
    insertAtTail(head2,7);
    insertAtTail(head2,8);
    insertAtTail(head2,10);
    display(head2);
    cout<<"The merged linked list : "<<endl;
    node* newhead = merge(head,head2);
    display(newhead);
    return 0;
}