#include<iostream>
using namespace std;

bool isvalid(int x ,int y ,int n ,bool placed[][5]){

    for(int i=0;i<x;i++){
        if(placed[i][y]) return false;
    }

    for(int i=x,j=y;i>=0&&j>=0;i--,j--){
       if(placed[i][j]) return false;
    }

    for(int i=x,j=y;i>=0&&j<n;i--,j++){
        if(placed[i][j]) return false;
    }

    return true;
}
 

void nqueen(int x ,int n,bool placed[][5]){

    if(x==n){

         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(placed[i][j])
                cout << "Q" << " ";
                else cout << "| " ;
            }
            cout << endl;
        }

        cout << endl;
        cout << endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(isvalid(x,i,n,placed)){
            placed[x][i]=true;
            nqueen(x+1,n,placed);
        }
        placed[x][i]=false;
    }

    return ;

}

int main(){

    bool placed[5][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            placed[i][j]=false;
        }
    }

   
    nqueen(0,5,placed);
       
}

