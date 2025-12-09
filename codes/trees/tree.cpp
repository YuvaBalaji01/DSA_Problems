#include<iostream>
#include<vector>
#include<queue>
#include"tree.h"
using namespace std;

treenode<int>* takeinputlevelwise(){
    queue<treenode<int>*>q;
    int d;
    cout << "enter the root node data:";
    cin >> d;
    treenode<int>* root=new treenode<int>(d);
    q.push(root);

    while(q.size()!=0){
        treenode<int>* front=q.front();
        q.pop();
        int c;
        cout << " enter the childern of " << front->data << " ";
        cin >> c;
        for(int i=0;i<c;i++){
            int cd;
            cout << " enter the data of " << i << "th child of " << front->data << " ";
            cin >> cd;
            treenode<int>* child =new treenode<int>(cd);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

treenode<int>* takeinput(){
    int data;
    cout << "enter the data:" ;
    cin >> data;
    treenode<int>*root=new treenode<int>(data);
    cout << "no.of childern to "<< root->data<<":";
    int c;
    cin >> c;
    for(int i=0;i<c;i++){
       treenode<int>* child=takeinput();   
       root->children.push_back(child);
    }
   
  return root;
}

void printgood(treenode<int>* root){
    queue<treenode<int>*> q;
    q.push(root);

    while(q.size()!=0){
        treenode<int>* front = q.front();
        q.pop();
        int n =front->children.size();
        cout << front->data << " : ";
        for(int i=0;i<n;i++){
            if(i==n-1) cout << front->children[i]->data ;
            else cout << front->children[i]->data << ",";
            q.push(front->children[i]);
        }
        cout << endl;
    }

}

void print(treenode<int>* root){
    cout << root->data <<":";
    for(int i=0;i<root->children.size();i++){
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
}

int main(){

  treenode<int>* root=takeinputlevelwise();
  printgood(root);
  delete root;

}