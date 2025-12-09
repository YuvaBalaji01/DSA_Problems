#include <iostream>
#include <cstring>
using namespace std;



bool isPermutation(char input1[], char input2[]) {
    // Write your code here
   int n=strlen(input1);
   int arr[26]={0};
   for(int i=0;i<n;i++){
       arr[input1[i]-97]+=1;
   }
   for(int i=0;i<n;i++){
       arr[input2[i]-97]-=1;
   }
   for(int i=0;i<26;i++){
       if(arr[i]!=0) return false;
   }
   return true;
}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}