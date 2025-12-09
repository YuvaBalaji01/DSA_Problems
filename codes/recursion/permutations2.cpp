#include<iostream>
#include<string>
using namespace std;

void per(string s,string c,int idx){

    if(s.length()==0) {
        cout << c<< endl;
        return;
    }

    for(int i =0;i<s.length();i++){

        string rem = s.substr(0,i)+s.substr(i+1);
        c = c+s[i];
        per(rem,c,i+1);
        c.pop_back();

    }
    
    c.pop_back();
    return;
}

int main(){

    string s = "abc";
    
    per(s,"",0);
}