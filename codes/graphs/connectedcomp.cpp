#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(int ** graph,int * visited,int s,int n,vector<int> &a){

    visited[s]=1;
    a.push_back(s);
    for(int i=0;i<n;i++){
        if(graph[s][i]==1 && visited[i]!=1){
            dfs(graph,visited,i,n,a);
        }
    }

   
    return ;
}

int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;

    int ** graph = new int*[v];

    for(int i=0;i<v;i++){
        graph[i]= new int[v];
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }

    int * visited = new int[v];
    for(int i=0;i<v;i++) visited[i]=0;

    for(int i=0;i<e;i++){

        int f,t;
        cin >> f >> t;

        graph[f][t]=1;
        graph[t][f]=1;
    }

    vector<vector<int>> c;
    int k=0;
    for(int i=0;i<v;i++){
        
        if(visited[i]!=1){
            vector<int> a;
            dfs(graph,visited,i,v,a);
            sort(a.begin(),a.end());
            c.push_back(a);
        }   
        

    }

    for(auto & i : c){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;

    }
}