#include <iostream>
#include<queue>
#include "BinaryTree.h"
using namespace std;

BinaryTree<int>* TakeInput(){
    int data;
    cout << " enter the root data" << " ";
    cin >> data;

    queue<BinaryTree<int>*> q;

    if(data==-1) return NULL; 

    BinaryTree<int> * root =  new BinaryTree<int>(data);

    q.push(root);
    
    while(q.size()!=0){
        BinaryTree<int>* front = q.front();
        q.pop();
        int l,r;
        cout << "enter left data" <<front->data << " ";
        cin  >> l;
        cout << "enter right data" <<front->data << " ";
        cin >> r;
        if(l!=-1) 
        {front->left=new BinaryTree<int>(l);
        q.push(front->left);}
        if(r!=-1)
        {front->right=new BinaryTree<int>(r);
        q.push(front->right);}
        
        
    }

    return root;

}

void inordertraversal(BinaryTree<int>* root){
    if(root==NULL) return;

    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
   
    return;

}

void print(BinaryTree<int>* root){


    queue<BinaryTree<int>*> q;
    q.push(root);
    
    while(q.size()!=0){
        BinaryTree<int>* front =q.front();
        q.pop();

        cout << front->data << ":";
        cout << "L" <<front->left->data << " ";
        q.push(front->left);
        cout << "R" <<front->right->data ;
        q.push(front->right);

        cout << endl;



    }
}

int main (){

   BinaryTree<int> * root = TakeInput();

   //print(root);

   inordertraversal(root);

}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 