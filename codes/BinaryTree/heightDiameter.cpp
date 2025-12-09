#include <iostream>
#include<queue>
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

pair<int,int> heightdaimeter(BinaryTree<int>* root){
    if(root==NULL){
        pair<int ,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int ,int > l=heightdaimeter(root->left);
    pair<int ,int > r=heightdaimeter(root->right);

    int lh=l.first;
    int rh=r.first;
    int ld = l.second;
    int rd = r.second;

    int h = 1+max(lh,rh);
    int d = max(lh+rh,max(ld,rd));

    pair<int,int > ans;
    ans.first=h;
    ans.second=d;
    
    return ans;
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

   pair<int,int>p=heightdaimeter(root);

   cout << "height="<< p.first << "diameter=" << p.second << endl;

}
//1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1