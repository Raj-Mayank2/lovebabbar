#include <iostream>
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
void detectAndRemoveLoop(Node* head){
    if(head==NULL|| head->next==NULL){
        return;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        if(slow==fast){
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast){
        slow=head;
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
        }
        else{
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;
            }
        }
        fast->next!=nullptr;
    }
}
void printList(Node *head) {
    Node* curr=head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main() {
    Node *head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);

    head->next->next->next->next->next = head;

    detectAndRemoveLoop(head);
    printList(head);

    return 0;
}