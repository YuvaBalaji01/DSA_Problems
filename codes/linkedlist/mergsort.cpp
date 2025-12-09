#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node* sort(Node*head1,Node*head2){

	Node* head;


	if(head1->data<head2->data){
		head=head1;
		head1=head1->next;
	}
	else{
		head=head2;
		head2=head2->next;
	}

	Node* tail=head;

	while(head1!=NULL && head2!=NULL){
		if(head1->data<head2->data){
			tail->next=head1;
			head1=head1->next;
		}
		else{
			tail->next=head2;
			head2=head2->next;
		}
		tail=tail->next;
	}

	while(head1!=NULL){
		tail->next=head1;
		head1=head1->next;
		tail=tail->next;
	}

	while(head2!=NULL){
		tail->next=head2;
		head2=head2->next;
		tail=tail->next;
	}

	return head;
}



Node *mergeSort(Node *head)
{
	//Write your code here
	if(head==NULL || head->next==NULL) return head;
	Node* slow=head;
	Node* fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	Node* mid=slow->next;
	slow->next=NULL;
    
	Node* left=mergeSort(head);
	Node* right=mergeSort(mid);

	return sort(left,right);

	 
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}