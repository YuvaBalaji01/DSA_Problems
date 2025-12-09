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

int  heightoftree(treenode<int>* root){
     int height=1;


    for(int i=0;i<root->children.size();i++){
        int h = 1+heightoftree(root->children[i]);
        height=(height>h)?height:h;
    }

    return height;
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
  int s=heightoftree(root);
  cout << s << endl;
  printgood(root);
  delete root;
}