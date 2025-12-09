#include<iostream>
using namespace std;

int largestmatrix(int n,int input[][5]){

    int op[n][n];
    op[0][0]=(input[0][0]==0)?1:0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && input[i][j]==0) op[i][j]=1;
            if(i!=j && input[i][j]!=0) op[i][j]=0;
        }
    }

    for(int i=1;i<n;i++){
       bool row = true;
       bool col = true;
       for(int j=0;j<i;j++){
        if(input[i][j]!=0){
           row=false;
           break;
        }
       }
       for(int j=0;j<i;j++){
        if(input[j][i]!=0){
           col=false;
           break;
        }
       }

       if(input[i][i]!=0 || !col || !row) op[i][i]=op[i-1][i-1];

       else op[i][i]=op[i-1][i-1]+1;

    }

    return op[n-1][n-1];
}

int main(){

    int mat[5][5];
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }

    int ans = largestmatrix(n,mat);
    cout << ans << endl;
}