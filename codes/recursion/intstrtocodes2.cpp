#include<iostream>
#include<string>
using namespace std;

char getchar(int n){
    return 'a'+n-1;
}

void getcodes(string input ,string output){

if(input[0]=='\0'){
    cout << output << endl;
    return;
}

int fd = input[0]-'0';

if(fd>=1 && fd <10){
    char ch = getchar(fd);
    getcodes(input.substr(1),output+ch);
}

int num=0;
if(input[1]!='\0'){
    int sd = input[1]-'0';
    num=fd*10+sd;
}

if(num>=10 && num<=26){
    char ch = getchar(num);
    getcodes(input.substr(2),output+ch);
}

return;


}


int main(){

    string input="1123";
    string output="";

    getcodes(input,output);
}