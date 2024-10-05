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


Node* reverseLLkgroup(Node* head,int k){
    Node* curr=head;
    Node* next=NULL;
    Node* prev=NULL;
    int count=0;
    while(curr!=NULL&&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        head->next=reverseLLkgroup(next,k);
    }
    return prev;
}
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    display(head);
    cout<<endl;
    int k=2;
    head=reverseLLkgroup(head,k);
    display(head);
}