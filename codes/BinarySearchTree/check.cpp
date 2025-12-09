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

bool check(BST<int>* root){
    
    bool  lans,rans;
    if(root==NULL || (root->left==NULL  && root->right==NULL) ) return true;

    if(root->left!=NULL && root->left->data>root->data) lans= false;
    else lans= true;
    if(root->right!=NULL && root->right->data<root->data) rans= false;
    else rans= true;

    lans = check(root->left);
    if(!lans) return false;
    rans = check(root->right);

    return rans;

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

    cout << endl;

    bool ans = check(root);

    cout << ans << endl;

}