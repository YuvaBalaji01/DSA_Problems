#include<iostream>
#include<vector>
using namespace std;

bool isvalid(int x,int y,int n,int ** sudoko){

    if(x>=9 || y>=9) return false;
    if(sudoko[x][y]!=-1) return false;

    for(int i=0;i<9;i++){
        if(sudoko[x][i]==n) return false;
    }
    for(int i=0;i<9;i++){
        if(sudoko[i][y]==n) return false;
    }

    for(int i=0;i<9;i+=3){

    if(x>=i && x<=i+2 ){
        if(y>=0 && y<=2){
            for(int j=i;j<=i+2;j++){
                for(int k=0;k<=2;k++){
                    if(sudoko[j][k]==n) return false;
                }
            }
        }
        if(y>=3 && y<=6){
            for(int j=i;j<=i+2;j++){
                for(int k=3;k<=6;k++){
                    if(sudoko[j][k]==n) return false;
                }
            }
        }
        if(y>=6 && y<=8){
            for(int j=i;j<=i+2;j++){
                for(int k=6;k<=8;k++){
                    if(sudoko[j][k]==n) return false;
                }
            }
        }
           
        }
    }

    return true;
         
}


void ans(int x,int y,int ** sudoko){

    if(x>=9 && y>=9) return;

}
