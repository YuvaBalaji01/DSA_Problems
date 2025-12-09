#include<iostream>
using namespace std;

int main (){
    int arr[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> arr[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j||i+j==3|| i==0 || j==0 || i==3 || j==3){
                sum+=arr[i][j];
            }
        }
    }
    cout << sum << endl;
        
}