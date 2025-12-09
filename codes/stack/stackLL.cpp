#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    

    Node(){

    };

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class stack{

    int index;
    Node*head;
    public:
    
    stack(){
        index=0;
        head=NULL;
    }
    

    void push(int d){
       Node* n =new Node(d);
       if(head==NULL) head=n;
       else{
        Node* temp=head;
        head=n;
        head->next=temp;
       }

       index++;
        
    }

    void pop(){
        if(index==0) cout << "stack is empty" << endl;
        else 
       {Node*temp=head;
       head=head->next;
       delete temp;
       index--;}
    }

    int size(){
        return index;
    }

    bool isempty(){
        if(index==0) return true;
        else return false;
    }

    void top(){
        cout << head->data << endl;
    }

    
};


int main (){
    stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << s1.size() << endl;
    cout << s1.isempty() << endl;
    s1.top();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout << s1.isempty() << endl;
    

}