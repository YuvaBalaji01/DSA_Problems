#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#include"tree.h"

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

int getLeafNodeCount(treenode<int>* root) {
    // Write your code here
    if(root==NULL) return 0;

    int ans=0;

    if(root->children.size()==0) return 1;

    for(int i=0;i<root->children.size();i++){
        ans+=getLeafNodeCount(root->children[i]);
    }

    return ans;
}

treenode<int>* max(treenode<int>* root){
    treenode<int>* ans=root;

    for(int i=0;i<root->children.size();i++){
        treenode<int>* n=max(root->children[i]);
        ans=(ans->data>n->data)?ans:n;
    }

    return ans;
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



int main(){

  treenode<int>* root=takeinputlevelwise();
  treenode<int>* s=max(root);
  int leafs=getLeafNodeCount(root);
  cout << s->data << endl;
  printgood(root);
  delete root;
}