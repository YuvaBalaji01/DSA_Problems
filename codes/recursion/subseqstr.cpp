#include <iostream>
#include <string>
using namespace std;

int substrs(string input,string * output){

    if(input.empty()){
        output[0]="";
        return 1;
    }

    string smallstr = input.substr(1);
    int ss = substrs(smallstr,output);

    for(int i=0;i<ss;i++){
        output[i+ss]= input[0]+output[i];
    }

    return 2*ss;
}

int main(){

    string i = "abc";
    string* o = new string[1000];

    int s = substrs(i,o);

    for(int i=0;i<s;i++){
        cout << o[i] << endl;
    }
}