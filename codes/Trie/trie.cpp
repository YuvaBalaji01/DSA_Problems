#include<iostream>
#include"trie.h"
using namespace std;


void insertion(string word,Node* root){

    for(int i = 0;i<word.length();i++){

        int index = word[i] - 'a';

        if(root->child[index] == NULL) {

            Node* newindex = new Node(word[i]);
            root->child[index] = newindex;
            root = root->child[index];
            
        }

        else {

            root = root->child[index];
        }
      
    }

      root->cnt++; 


}

void remove(string word , Node* head){

    for(int i= 0;i<word.length();i++){

        int index = word[i] - 'a';

        if(head->child[index] != NULL) head = head->child[index];
        else return;
    }

    head->cnt--;
}

void print(Node* root, string &temp) {

    if (root->cnt > 0) {
        cout << temp << endl;
    }

    for (int i = 0; i < 26; i++) {

        if (root->child[i] != NULL) {
            temp.push_back(root->child[i]->data);
            print(root->child[i], temp);
            temp.pop_back();  
        }
    }
}


bool find(string word,Node* root){

    for(int i=0;i<word.length();i++){

        int index = word[i] -'a';

        if(root->child[index] != NULL) root = root->child[index];
        else return false;
    }

    if(root->cnt > 0) return true ;
    return false;
}

int main(){

    Node * root = new Node('$');
     
    int n;
    cin >> n;
    while(n--){

       string word;
       cin >> word;
       insertion(word,root);
    
    }

    string temp = "";
    print(root,temp);
    

}