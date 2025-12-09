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

bool find (BST<int> * root , int k){

	if(root== NULL) return false;

	if(root->data == k) return true;

	if(root->data > k) return find(root->left,k);
    else return find(root->right,k);
}



int getLCA(BST<int>* root , int val1 , int val2){
    // Write your code here

	if(root==NULL) return -1;

	if(root->data==val1 || root->data==val2) return root->data;
    
    bool lv1 = find(root->left,val1);
    bool lv2 = find(root->left,val2);
    bool rv1 = find(root->right,val1);
    bool rv2 = find(root->right,val2);
     int ans;
	if(lv1 && lv2)  ans =getLCA(root->left,val1,val2);
	if(rv1 && rv2)  ans =getLCA(root->right,val1,val2);
	else return root->data;

	return ans;

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

}