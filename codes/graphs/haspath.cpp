#include<iostream>
#include<stack>
using namespace std;

bool haspath(int ** graph,int *visited,int s,int e ,int n){

    visited[s]=1;
    if(graph[s][e]==1) return true;

    for(int i=0;i<n;i++){
        if(graph[s][i]==1 && visited[i]!=1){
          bool ans = haspath(graph,visited,i,e,n);
          if(ans) return true;
        }
    }

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
 
    int s,l;
    cin >> s >> l;
   int ans  = haspath(G,visited,s,l,n);
   cout << ans << endl;
    
}