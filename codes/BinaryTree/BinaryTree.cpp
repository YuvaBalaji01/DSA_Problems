#include <iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTree<int>* TakeInput(){
    int data;
    cout << " enter the data" << " ";
    cin >> data;

    if(data==-1) return NULL; 

    BinaryTree<int> * root =  new BinaryTree<int>(data);
    BinaryTree<int> * l =  TakeInput();
    BinaryTree<int> * r =  TakeInput();

    root->left=l;
    root->right=r;

    return root;

}
bool check(BinaryTree<int>* root){
    
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

void print(BinaryTree<int>* root){

    if(root==NULL) return; 

    cout << root->data << ":";

    if(root->left) cout << "L" << root->left->data << " ";
    if(root->right) cout << "R" << root->right->data << " ";

    cout << endl;

    print(root->left);
    print(root->right);
}

int main (){

   BinaryTree<int> * root = TakeInput();

   print(root);
   cout << endl;

   bool ans = check(root);

   cout << ans << endl;

}