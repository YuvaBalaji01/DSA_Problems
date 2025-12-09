#include<iostream>
using namespace std;

bool palindrom(int arr[],int n){
    if(n==0||n==1) return true;

    if(arr[0]!=arr[n-1]) return false;

    return palindrom(arr+1,n-2);
}

int main(){
    int arr[5]={1,2,3,3,1};
    cout << palindrom(arr,5) << endl;
    return 0;
}