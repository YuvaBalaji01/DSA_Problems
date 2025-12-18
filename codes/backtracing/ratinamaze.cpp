#include<iostream>
using namespace std;

bool isvalid(int maze[][10],int visited[][10],int x,int y,int n){

    if(x >=n || y >=n || x<0 || y<0) return false;

    if(maze[x][y]==-1 || visited[x][y]==1) return false;

    return true;
}

bool isexsist(int maze[][10],int visited[][10],int x,int y,int n){

    if(x==n-1 && y==n-1) return true;

   

      visited[x][y]=1;
       if(isvalid(maze,visited,x+1,y,n)){
         bool ans = isexsist(maze,visited,x+1,y,n);
         if(ans ) return ans;
       }
        if(isvalid(maze,visited,x-1,y,n)){
         bool ans = isexsist(maze,visited,x-1,y,n);
         if (ans) return ans;
        }
        if(isvalid(maze,visited,x,y-1,n)){
         bool ans =isexsist(maze,visited,x,y-1,n);
         if(ans) return ans;
        }
        if(isvalid(maze,visited,x,y+1,n)){
         bool ans =isexsist(maze,visited,x,y+1,n);
         if(ans ) return ans;
        }
    
       visited[x][y]=0;

    return  false;
}

int main(){

    int maze[10][10];
    int n ;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> maze[i][j];
        }
    }

    int visited[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }

    cout << isexsist(maze,visited,0,0,n) << endl;

}

