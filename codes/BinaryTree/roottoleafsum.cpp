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

void helper(BinaryTree<int>* root , vector<int> v ,int k){

    if(root==NULL) return;

    k-=root->data;
    v.push_back(root->data);

    if(k==0 && (root->left==NULL && root->right== NULL) ){
        for(int i=0;i<v.size();i++) cout << v[i] << " ";
        cout << endl;
        v.pop_back();
    }

    helper(root->left,v,k);
    helper(root->right,v,k);

    v.pop_back();

    return;
}

void roottoleafsum(BinaryTree<int> * root , int k){
    vector<int> v;
    helper(root,v,k);
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

   roottoleafsum(root,13);

}

// 6 3 7 1 5 8 9 -1 -1 4 -1 -1 -1 -1 -1 -1 -1