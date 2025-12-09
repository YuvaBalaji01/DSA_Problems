#include<iostream>
#include<vector>
using namespace std;

bool isvalid(int x ,int y,int n,vector<vector<int>> &visited,vector<vector<int>> & maze){

    if(x<0 || x>=n ||y<0 || y>=n ) return false;

    if(visited[x][y]==1 || maze[x][y]==0) return false;

    return true;
}


void solution(int x,int y,int n,vector<vector<int>> & visited,vector<vector<int>> & maze,vector<vector<int>> & ans){

    if(x==n-1 && y==n-1){
        vector<int> c;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                c.push_back(visited[i][j]);
            }
        }

        ans.push_back(c);
    }

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    for(int i=0;i<4;i++){

        if(isvalid(x+dx[i],y+dy[i],n,visited,maze)){
            visited[x+dx[i]][y+dy[i]]=1;
            solution(x+dx[i],y+dy[i],n,visited,maze,ans);
            visited[x+dx[i]][y+dy[i]]=0;
        }
    }

    return ;
}