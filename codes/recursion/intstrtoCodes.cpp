#include<iostream>
#include<string>
using namespace std;

char getchar(int n){
    return 'a'+n-1;
}

int getcodes(string input,string op[]){

    if(input[0]=='\0'){
        op[0]="";
        return 1;
    }

    string smallstr1[1000];
    string smallstr2[1000];
    int  fd = input[0]-'0';
    int size1=0;
    if(fd>=1 && fd<=9){
        size1 = getcodes(input.substr(1),smallstr1);
        char ch = getchar(fd);
        for(int i=0;i<size1;i++){
            op[i]=ch+smallstr1[i];
        }
       
    }

    int size2=0;
   
    int num=0;
    if(input[1]!='\0'){
        int sd=input[1]-'0';
        num =fd*10+sd;
    }
   
    
    if(num>=10 && num<=26){
        size2=getcodes(input.substr(2),smallstr2);
        char ch = getchar(num);
        for(int i=0;i<size2;i++){
            op[i+size1]=ch+smallstr2[i];
        }
        

    }

   
    return size1+size2;



}



int main(){

    string input = "1123";
    string op[10000];

    int size  = getcodes(input,op);

    for(int i=0;i<size;i++){
        cout << op[i] << endl;
    }

}
