#include <iostream>
#include <queue>
using namespace std;

void bfs(int **graph, int *visited, int v, int start) {

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int n = q.front();
        q.pop();
        if(!visited[n]){
            cout << n << " ";
            visited[n]=1;
        }

        for(int i=0;i<v;i++){
            if(graph[n][i]==1 && !visited[i]){
                cout << i << " ";
                visited[i]=1;
                q.push(i);
            }
        }
    }
    
}

void print(int **graph, int *visited, int v) {
    
    if(!visited[0]) bfs(graph,visited,v,0);

    for(int i=1;i<v;i++){
        if(!visited[i]) bfs(graph,visited,v,i);
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    int **graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) graph[i][j] = 0;
    }

    int *visited = new int[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < e; i++) {
        int s, t;
        cin >> s >> t;
        graph[s][t] = 1;
        graph[t][s] = 1;  // undirected
    }

    print(graph, visited, n);

    delete [] visited;
    for (int i = 0; i < n; i++) delete [] graph[i];
    delete [] graph;

    return 0;
}
