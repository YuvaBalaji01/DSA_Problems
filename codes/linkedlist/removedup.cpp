#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* removeDuplicates(Node* head) {
    if (head == NULL) return head;

    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp; // Free memory
        } else {
            current = current->next;
        }
    }

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insert(){
    int data;
    cin >> data;
    Node* head = NULL;
    Node * tail = NULL;
    while(data!=-1){
        Node *newnode= new Node(data);
        
        
        if(head==NULL) {head=newnode; tail = head;}
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin >> data;
    }
    return head;
}

int main(){
   Node*head=insert();
   printList(head);
   head=removeDuplicates(head);
   printList(head);

}
