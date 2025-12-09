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

int maxx(BinaryTree<int>* root){
    if(root==NULL) return INT_MIN;

    int l = maxx(root->left);
    int r = maxx(root->right);

    int ans=max(root->data,max(l,r));

    return ans;
}

int minn(BinaryTree<int>* root){
    if(root==NULL) return INT_MAX;

    int l = minn(root->left);
    int r = minn(root->right);

    int ans=min(root->data,min(l,r));

    return ans;
}

bool check(BinaryTree<int>* root){
     
    if(root==NULL) return true;

    int maxl = maxx(root->left);
    int minr= minn(root->right);

    if(root->data < maxl || root->data > minr) return false;

    bool l=check(root->left);
    if(!l) return false;
    bool r=check(root->right);
    if(!r) return false;

    return true;

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

   bool ans = check(root);
    if (ans)
   cout <<"true"  << endl;
   else cout << "false " << endl;

}

// 6 3 7 1 5 8 9 -1 -1 4 -1 -1 -1 -1 -1 -1 -1