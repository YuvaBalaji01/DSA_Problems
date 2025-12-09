#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(int ** graph,int* visited,int s ,int n ,vector<int> &v){

    visited[s]=1;
    v.push_back(s);
    for(int i=0;i<n;i++){

        if(graph[s][i]==1 && visited[i]!=1){
            dfs(graph,visited,i,n,v);
        }
    }

    return;
}

bool connected(int ** graph,int *visted,int n){
    
    vector<int> v;
    dfs(graph,visted,0,n,v);

    if(v.size()==n) return true;

    return false;

}


int main(){

    int n,e;
    cin >>n >> e;

    int ** G = new int*[n];
    for(int i=0;i<n;i++) G[i] = new int[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            G[i][j]=0;
        }
    }

    int * visited = new int[n];

    for(int i=0;i<n;i++) visited[i]=0;

    for(int i=0;i<e;i++){
        int s , l;
        cin >> s >> l;
        G[s][l]=1;
        G[l][s]=1;
    }
    bool ans;
    if(e<n-1) cout << false<< endl;
    else {
    ans =connected(G,visited,n);
    cout << ans << endl;}
}