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

pair<BST<int>*,BST<int>*> sucessor(BST<int>* s,BST<int>* sp){

    
    

    if(s->left== NULL){
        pair<BST<int>*,BST<int>*> ans(s,sp);
       return ans;
    }

    sp=s;
    s=s->left;

    

    pair<BST<int>*,BST<int>*> ans = sucessor(s,sp);

     return ans;
}

BST<int>* deletion(BST<int>* root, int val){
     
    if(root==NULL) return NULL;
    if(root->data==val){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            BST<int>* temp =root->left;
            delete root;
            return temp;

        }
        else if(root->left==NULL && root->right!=NULL){
            BST<int>* temp =root->right;
            delete root;
            return temp;

        }
        else {

            pair<BST<int>*,BST<int>*> ssp = sucessor(root->right,root);
            BST<int>* s =ssp.first;
            BST<int>* sp =ssp.second;
            root->data=s->data;
            sp->left=s->right;
            delete s;
            return root;

        }
    }

    if(root->data>val)
    root->left=deletion(root->left,val);
    else root->right=deletion(root->right,val);

    return root;

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
    root=insert(root,3);
    root=insert(root,2);
    root=insert(root,1);
    root=insert(root,6);
    root=insert(root,5);
    root=insert(root,9);
    root=insert(root,7);
    root=insert(root,8);

    deletion(root,1);
    print(root);

    
    deletion(root,6);
    print(root);

}