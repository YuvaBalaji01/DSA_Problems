#include <iostream>
#include<queue>
#include <climits>
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

int * largestBST(BinaryTree<int>* root){

    if(root==NULL){
        int * res = new int[3];
        res[0]=INT_MAX;
        res[1]=INT_MIN;
        res[2]=0;
        return res;
    }

    int* L = largestBST(root->left);
    int *R = largestBST(root->right);

    if(root->data > L[1] && root->data <R[0]){

        int * res = new int[3];
        res[0]=min(root->data ,min(L[0],R[0]));
        res[1]=max(root->data,max(L[1],R[1]));
        res[2]=max(L[2],R[2])+1;
        return res;

    }

    else{

         
        int * res = new int[3];
        res[0]=INT_MIN;
        res[1]=INT_MAX;
        res[2]=max(L[2],R[2]);
        return res;


    }
}

void print(BinaryTree<int>* root){


    queue<BinaryTree<int>*> q;
    q.push(root);
    
    while(q.size()!=0){
        BinaryTree<int>* front =q.front();
        q.pop();

        cout << front->data << ":";
        if(front->left) {
        cout << "L" <<front->left->data << " ";
        q.push(front->left);
        }
        if(front->right){
        cout << "R" <<front->right->data ;
        q.push(front->right);
        }

        cout << endl;



    }
}

int main (){

   BinaryTree<int> * root = TakeInput();

   print(root);

    int* arr = largestBST(root);

    cout << arr[2] << endl;


    
}

// 6 3 7 1 5 8 9 -1 -1 4 -1 -1 -1 -1 -1 -1 -1