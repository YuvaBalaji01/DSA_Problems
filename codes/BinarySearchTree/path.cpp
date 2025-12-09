#include<iostream>
#include<vector>
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

pair<vector<int>*,bool> helper(BST<int>* root,int k){

    vector<int>* a;
    pair<vector<int>*,bool> ans;
    ans.first=a;
    ans.second=false;

    if(root==NULL) return ans;

     if(root->data == k)  {
        (ans.first)->push_back(k);
        ans.second=true;
        return ans ;

     }

    if(root->data > k){
        ans =helper(root->left,k);
        if ( ans.second ) ans.first->push_back(root->data);
        return ans;
    }

    if(root->data < k){
        ans =helper(root->right,k);
        if ( ans.second) ans.first->push_back(root->data);
        return ans;
    }

}

vector<int>* path(BST<int>* root,int k){
    
    pair<vector<int>*,bool> ans = helper(root,k);

    if(!(ans.second)) return NULL;

    return ans.first;
    
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
    root=insert(root,35);
    root=insert(root,20);
    root=insert(root,15);
    root=insert(root,24);
    root=insert(root,19);
    root=insert(root,10);
    root=insert(root,40);
    root=insert(root,55);
    root=insert(root,50);

    print(root);

    cout << endl;

    path(root,19);

}