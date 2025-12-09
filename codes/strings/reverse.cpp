#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // Your code here
    char input[1000]="balaji";
    int n= strlen(input);
    for(int i=0;i<n/2;i++){
      char ch =input[i];
        input[i]=input[n-1-i];
        input[n-1-i]=ch;
    }
    cout << input << endl;
        
    return 0;
}