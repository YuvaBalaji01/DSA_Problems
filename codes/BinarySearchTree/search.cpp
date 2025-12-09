#include<iostream>
using namespace std;
#include "BST.h"

BST<int>* insert(BST<int>* root,int d){
    if(root==NULL){
        return new BST<int>(d);
    }

    if(root->data==d){
        (root->count)++;
    }

    else if(root->data > d){
        BST<int>* t = insert(root->left,d);
        root->left=t;
    }

    else{
        BST<int>* t = insert(root->right,d);
        root->right=t;
    }

    return root;
}

bool search(BST<int>* root , int k){

    if(root==NULL) return false;

    if(root->data==k) return true;

    if(root->data > k) return search(root->left,k);
    else return search(root->right,k);






}

void print(BST<int>* root){
    if(root==NULL) return;

    print(root->left);
    cout << root->data <<" " << root->count <<endl;
    print(root->right);

    return;
}

int main (){

    BST<int>* root =NULL;
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,3);
    root=insert(root,5);
    root=insert(root,5);
    root=insert(root,7);
    root=insert(root,6);
    root=insert(root,1);
    root=insert(root,8);

    print(root);

    bool ans =search(root,8);

    cout << ans << endl;

}