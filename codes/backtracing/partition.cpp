#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool ispalindrom(string str){

    int s =0;
    int e =str.length()-1;

    while(s<e){

        if(str[s]!=str[e]) return false;

        s++;
        e--;
    }

    return true;
}

void partionpalindrom(string str,int st,vector<string> &c,vector<vector<string>> &ans){

    if(st==str.length()){
       ans.push_back(c);
       return ;
    }

    for(int i=st;i<str.length();i++){

        if(ispalindrom(str.substr(st,i-st+1))){

            c.push_back(str.substr(st,i-st+1));
            partionpalindrom(str,i+1,c,ans);
            c.pop_back();
        }

    }
   
   

    
}

int main(){
    string s= "BaaB";
    vector<string> c;
    vector<vector<string>> ans ;

   partionpalindrom(s,0,c,ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }
}