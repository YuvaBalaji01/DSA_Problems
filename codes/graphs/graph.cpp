#include<iostream>
#include<stack>
using namespace std;

void printBFS(int ** G,int n,int e,int *visited,int sv){

    if(visited[sv]==0){
        visited[sv]=1;
        cout << sv << " ";
    }


    for(int i=0;i<n;i++){

        if(i == sv || visited[i]==1) continue;

        if(G[sv][i]==1) {
            visited[i]=1;
            cout << i << " ";
        }
    }
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

    for(int i=0;i<n;i++){
        printBFS(G,n,e,visited,i);
    }

    
}