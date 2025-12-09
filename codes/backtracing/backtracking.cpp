#include<iostream>
#include<vector>
using namespace std;

bool isvalid(int x,int y,int n,bool  visited[][3] ,char cell[][3]){

    if(x<0 || x>=n || y<0 || y>=n) return false;

    if(visited[x][y] || cell[x][y]=='X') return false;

    return true;
}


bool rout(int x , int y,int n ,bool  visited[][3] , char cell[][3]){

    if(x==n-1 && y==n-1) return true;

    if(isvalid(x,y-1,n,visited,cell)){
        visited[x][y-1]=true;
        if(rout(x,y-1,n,visited,cell)){
            return true;
        }
    }
    if(isvalid(x,y+1,n,visited,cell)){
        visited[x][y+1]=true;
        if(rout(x,y+1,n,visited,cell)){
            return true;
        }
    }
    if(isvalid(x+1,y,n,visited,cell)){
        visited[x+1][y]=true;
        if(rout(x+1,y,n,visited,cell)){
            return true;
        }
    }
    if(isvalid(x-1,y,n,visited,cell)){
        visited[x-1][y]=true;
        if(rout(x-1,y,n,visited,cell)){
            return true;
        }
    }

    visited[x][y]=false;
    return false;

}


int main(){

    char cell[3][3];
    bool visited[3][3];
    for(int i=0;i<3;i++ ){
        for(int j=0;j<3;j++){
            cell[i][j]='o';
            visited[i][j]=false;
        }
    }

    cell[1][1] ='X';
    cell[1][2] ='X';
    cell[1][0] = 'X';

    bool ans = rout(0,0,3,visited,cell);
    cout << ans << endl;



}