#include<iostream>
#include<string>
using namespace std;

// not completely correct line 70 need to be changed

bool isvalid(int x ,int y,int n ,int idx , bool visited[][3],string wrd , char grid[][3]){

    if(x<0 || x>=n || y<0 || y>=n ) return false;

    if(visited[x][y] || grid[x][y]!=wrd[idx]) return false;

    return true;
}

bool word(int x ,int y ,int n, int idx , bool visited[][3], string wrd , char grid[][3]){

    if(idx==wrd.length()-1) return true;

    if(isvalid( x ,y-1, n , idx+1,visited,wrd,grid)){

        visited[x][y-1]=true;
        if(word(x,y-1,n,idx+1,visited,wrd,grid)) return true;

    }
    if(isvalid( x ,y+1, n , idx+1,visited,wrd,grid)){

        visited[x][y+1]=true;
        if(word(x,y+1,n,idx+1,visited,wrd,grid)) return true;

    }
    if(isvalid( x-1 ,y, n , idx+1,visited,wrd,grid)){

        visited[x-1][y]=true;
        if(word(x-1,y,n,idx+1,visited,wrd,grid)) return true;

    }
    if(isvalid( x+1 ,y, n , idx+1,visited,wrd,grid)){

        visited[x+1][y]=true;
        if(word(x+1,y,n,idx+1,visited,wrd,grid)) return true;

    }

    visited[x][y] = false;
    return false;
}

int main(){

    char grid[3][3]={{'a','c','x'},{'p','t','y'},{'c','p','a'}};
    bool visited[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) {
            visited[i][j]=false;
        }
    }

    string s = "pat";

    int x=-1,y=-1;
    int i=0,j=0;
    bool ans =false;

    

    for(;i<3 && ! ans;i++){
        for(;j<3 && !ans;j++) {
           if(grid[i][j]==s[0]){
            visited[x][y]=true;
            ans = word(i,j,3,0,visited,s,grid);
            break;
           }
        }
    }

    
    
   if(ans ) cout << s << "ispresent" << endl;
   else cout << s << " Not present" << endl;
}