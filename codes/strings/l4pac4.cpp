#include<iostream>
using namespace std;

int main(){
    char input[10]="aabbbcccc";
    int arr[26]={0};
    for(int i=0;input[i]!='\0';i++){
       arr[input[i]-97]++;
    }
    int max =arr[0];
    int index;
    for(int i=0;i<26;i++){
        
        if(arr[i]>max){
           max=arr[i];
           index=i;
        }
    }
    char r = 97+index;
    cout << r << endl;
}