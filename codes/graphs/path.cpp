#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

bool path(int ** graph,int *visited,vector<int> & v,int s,int e,int n){
   
   if(n==0 ) return false;
    visited[s]=1;
    v.push_back(s);
   if(s==e) return true;

   for(int i=0;i<n;i++){
    if(graph[s][i]==1 && visited[i]!=1){
        int ans = path(graph,visited,v,i,e,n);
        if(ans) return true;
    }
   }

   v.pop_back(); 
   return false;
    
}

bool pathbfs(int **graph,int* visited,int s,int e,int n,unordered_map<int,int> &m){

    queue<int> q;
    q.push(s);
    visited[s]=1;
   
   
    while(!q.empty()){

        int ci  = q.front();
        q.pop();

        for(int i=0;i<n;i++){
            
            if(graph[ci][i]==1 && visited[i]!=1){
                m[i]=ci;
                visited[i]=1;
                q.push(i);
                
            }
            if(visited[e]==1) return true;
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

    vector<int> v;
 
    int s,l;
    cin>>s>>l;
    unordered_map<int,int> m;
   int ans  = pathbfs(G,visited,s,l,n,m);
   if(ans ){

   cout << l << " ";
   int x =l;
   while(x!=s){
    x=m[x];
    cout << x << " ";
   }
   
}


    
}