#include<iostream>
using namespace std;

bool isvalid(int x,int y ,bool placed[][5],int n){
    for(int i=0;i<x;i++){
        if(placed[i][y])  return false;
    }

    for(int i=x , j=y; j>=0 && i>=0 ; i--,j--){
        if(placed[i][j]) return false;
    }
    for(int i=x, j=y; j<n && i>=0 ; i--,j++){
        if(placed[i][j]) return false;
    }

    return true;

    
}


bool nqueen(int x ,int y,bool placed[][5],int n){

    if(x==n) return true;

    for(int i=0;i<n;i++){
        if(isvalid(x,i,placed,n)){
            placed[x][i]=true;
           if (nqueen(x+1,y,placed,n)) return true;
        }
        placed[x][i]=false;
    }

   
    return false;
}

int main(){

    bool placed[5][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            placed[i][j]=false;
        }
    }

    bool ans = nqueen(0,0,placed,5);

    if(ans){

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(placed[i][j])
                cout << "Q" << " ";
                else cout << "| " ;
            }
            cout << endl;
        }
    }

}