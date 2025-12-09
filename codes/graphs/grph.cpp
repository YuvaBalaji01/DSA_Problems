#include<iostream>
#include<stack>
using namespace std;

void printBFS(int ** grph,int n,int sv,int * visited){

    stack<int> s;
    s.push(sv);
    cout << sv << " ";

    while(!(s.empty())){

        int se = s.top();
        s.pop();
        visited[se]=1;
        

        for(int i=0;i<n;i++){
            if(i==se || visited[i]==1) continue;

            if(grph[se][i]==1) {
                if( visited[i]==0){
                  s.push(i);
                  visited[i]=1;
                }
                
                cout << i << " ";
      
            }
        }

        stack<int> s2;

        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }

        s=s2;
        
    }

}

// DFS 
void print(int ** grph,int n,int sv,int * visited){

    if(visited[sv]==1) return;

    cout << sv << " ";
    visited[sv]=1;

    for(int i=0;i<n;i++){
        if(i == sv || visited[i]==1) continue;

        if(grph[sv][i]==1) {
            
            print(grph,n,i,visited);
        }
    }

}

int main(){

    int n,e;
    cin >> n >> e;

    int ** graph = new int*[n];

    for(int i=0;i<n;i++){
        graph[i] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout << "is there a edge b/w (0/1)" <<i <<"&" <<j << endl;
            int c;
            cin >> c;
            if(c==1){
                graph[i][j]=1;
                graph[j][i]=1;
            }
            else {
                graph[i][j]=0;
                graph[j][i]=0;
            }
        }
    }
    int * visited = new int[n];

    for(int i=0;i<n;i++) visited[i]=0;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << graph[i][j] << " ";
    //     }

    //     cout << endl;
    // }
     
    printBFS(graph,n,0,visited);

    delete [] visited;

    for(int i=0;i<n;i++) delete [] graph[i];

    delete [] graph;

    
}