#include <iostream>
#include <cstring>
using namespace std;

void reverseEachWord(char input[]) {
    // Write your code here
   int n=strlen(input);
   int end, start=0;
   for(int i=0;i<=n;i++){
       if(input[i]==' '||input[i]=='\0'){
         end=i-1;
         while(start<=end){
             char ch=input[start];
             input[start]=input[end];
             input[end]=ch;
             start++;
             end--;
         }
         start=i+1;
       }
       
       
   }
   
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}