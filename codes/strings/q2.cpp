#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[]) {
    // Write your code here
    int n= strlen(input);
    char lch=input[0];
    int j=1;
    for(int i=1;i<n;i++){
        if(lch!=input[i]){
            lch=input[i];
            input[j]=input[i];
            j++;
        }
    }
    input[j]='\0';
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}