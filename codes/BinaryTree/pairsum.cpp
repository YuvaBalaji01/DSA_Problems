#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
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

vector<int> add(BinaryTree<int>* root){
    vector<int> a;
    if(root==NULL) return a;

    a.push_back(root->data);

    vector<int> lv = add(root->left);

    for(int i=0;i<lv.size();i++) a.push_back(lv[i]);

    vector<int> rv = add(root->right);

    for(int i=0;i<rv.size();i++) a.push_back(rv[i]);

    return a;

}

void pairsum(BinaryTree<int>* root , int k){

    if(root==NULL) return ;

    vector<int> v = add(root);

    sort(v.begin(),v.end());

    int i=0;
    int j = v.size()-1;

    while(i<j){

        if(v[i]+v[j]==k){
            cout << v[i] << " " << v[j] << endl;
            i++;j--;
        }

        else if(v[i]+v[j]> k) j-- ;

        else i++ ;
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

   pairsum(root,10);

}

// 6 3 7 1 5 8 9 -1 -1 4 -1 -1 -1 -1 -1 -1 -1