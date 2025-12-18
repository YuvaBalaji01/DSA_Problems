#include<iostream>
#include"trie.h"
using namespace std;


void insertion(string word,Node* root){

    for(int i = 0;i<word.length();i++){

        int index = word[i] - 'a';

        if(root->child[index] == NULL) {

            Node* newindex = new Node(word[i]);
            root->child[i] = newindex;
            root = root->child[i];
            delete newindex;
        }

        else {

            root = root->child[i];
        }

        root->isterminal = true;
    }


}

int main(){

    string word;
    cin >> word;

    Node * root = new Node('$');

    insertion(word,root);
    

}