#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data=val;
        this->next=NULL;
    }
};

void display(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* reverse(Node* head){
    Node* curr=head;
    Node* next=NULL;
    Node* prev=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    display(head);

    head=reverse(head);
    display(head);
}