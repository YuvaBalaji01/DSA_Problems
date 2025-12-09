#include<iostream>
using namespace std;

class Node {
    public:

    int data;
    Node * next;

    Node(int d ){
        data = d;
        next = NULL;
    }

};

Node* takeinput(){

    int d;
    cin >> d;
    Node* tail =NULL;
    Node* head=NULL;
    while(d!=-1){
       
        Node * newnode = new Node(d);
        if(head==NULL) {head = newnode;
        tail = newnode;}

        else {

            tail->next = newnode;
            tail = newnode;
        }
        cin >> d;
    }

    return head;
}

void print(Node * head){
   Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    return;
}


int main(){

    Node * root = takeinput();

    print(root);
}