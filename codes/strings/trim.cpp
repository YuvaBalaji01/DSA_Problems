#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) {
    // Write your code here


    for(int i=0;input[i]!='\0';i++){
        if(input[i]==' ') {
            for(int j=i+1;input[j]!='\0';j++){
                if(input[j]!=' '){
                    char t=input[j];
                    input[j]=input[i];
                    input[i]=t;
                    break;
                }
            }
        }
    }
   
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}

